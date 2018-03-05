<?php
	require_once("User.class.php");
	require_once("Game.class.php");
	require_once("gamedata.php");
	require_once("./accounts/auth.php");

	$game = null;
	$state = null;
	$user = retrieve_session();

	if ($user !== false && ($game = game_session(10)) === false) {
		$game = new Game(array($user, $user), 150, 100);
		$game->populate(true);
		game_session_save(10, $game);
	}

	if (array_key_exists("id", $_GET) && ($game = game_session($_GET["id"])) !== false && $game->getState()["active"]) {
		$players = $game->getPlayers();
		if ($user !== false && $user->getLogin() == $players[$game->getState()["player"]]->getLogin()) {
			$game->resume();
			game_session_save($_GET["id"], $game);
		}

		$state = $game->getState();
		if (!($state["active"])) {
			game_session_clear($_GET["id"]);

			$mutex = mutex_lock();
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db"));

			foreach ($players as $user) {
				if ($state["result"] == "DRAW" || $players[$state["player"]]->getLogin() != $user->getLogin()) {
					if (array_key_exists($user->getLogin(), $db))
						$db[$user->getLogin()]->losses++;
				}
				else {
					if (array_key_exists($user->getLogin(), $db))
						$db[$user->getLogin()]->wins++;
				}
			}

			file_put_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db", serialize($db));
			mutex_unlock($mutex);
		}
	}
	else if (empty($_POST))
		header("Location: ./index.php");

	if (!empty($_POST)) {
		if ($game !== null && $game !== false && array_key_exists("action", $_POST)) {
			switch ($_POST["action"]) {
				case "JS":
					echo($game->generateJSPayload());
					break;

				case "BOARD":
					echo($game->generateBoard());
					break;

				case "LR":
					echo("<table><tr><td class=\"split\">");
					echo($game->generateLeft());
					echo("</td><td class=\"split\">");
					echo($game->generateRight());
					echo("</td></tr></table>");
					break;
			}
		}

		exit();
	}
?>
<script src="https://code.jquery.com/jquery-3.1.0.min.js"></script>
<script id="sync">
<?php
	echo($game->generateJSPayload());
?>
</script>
<style>
	td.cell {
		height: 45px;
		min-width: 42px;
		width: 42px;
		border: 1px groove gainsboro;
	}
	img {
		height: 40px;
		width: 42px;
	}
	img.rotate90 {
		transform: rotate(90deg);
	}
	img.rotate180 {
		transform: rotate(180deg);
	}
	img.rotate270 {
		transform: rotate(270deg);
	}
	body {
		font-family: Consolas, monaco, monospace;
		margin: 0 0 151px;
	}
	div.footer {
		position: fixed;
		left: 0;
		bottom: 0;
		height: 150px;
		width: 100%;
		background-color: black;
		color: white;
	}
	td.split {
		font-size: 12px;
		width: 48vw;
		vertical-align: top;
		color: white;
	}
	.p1_frag
	{
		background:#ff0000;
		opacity:0.6;
	}
	.p2_frag
	{
		background:#00ff00;
		opacity:0.6;
	}
	.p3_frag
	{
		background:#0000ff;
		opacity:0.6;
	}
	.p4_frag
	{
		background:#ffff00;
		opacity:0.6;
	}
	.highlight {
    	background-color:lightgray;
	}
</style>
<body background="http://s3.amazonaws.com/everystockphoto/fspid30/31/20/07/2/tileable-classic-nebula-3120072-o.jpg">
<?php
	$board = $game->generateBoard();
	echo($board);
?>
<div class="footer">
<?php
	echo("<table><tr><td class=\"split\">");
	echo($game->generateLeft());
	echo("</td><td class=\"split\">");
	echo($game->generateRight());
	echo("</td></tr></table>");
?>
</div>
</body>
<script>
	function get_fields(form, final) {
		var result = {};
		for (var i = 0; i < form.childNodes.length; i++)
			result[form.childNodes[i].name] = form.childNodes[i].value;
		result[final.name] = final.value;
		return (result);
	}

	function update() {
		$.post("",
			{ action: "JS" },
			function(data) {
				$("#sync").empty();
				$("#sync").append(data);
			}
		);

		$.post("",
			{ action: "BOARD" },
			function(data) {
				$("#board").remove();
				$("body").prepend(data);
			}
		);

		$.post("",
			{ action: "LR" },
			function(data) {
				$("input[type='submit']").off("click");

				$(".footer").empty();
				$(".footer").append(data);

				$("input[type='submit']").click(function(event) {
					event.preventDefault();
					$.post("",
						get_fields($(this).closest("form").get(0), this),
						function(data) {
							update();
						}
					);
				});
			}
		);
	}

	$(document).ready(function() {
		$("input[type='submit']").click(function(event) {
			event.preventDefault();
			$.post("",
				get_fields($(this).closest("form").get(0), this),
				function(data) {
					update();
				}
			);
		});

		setInterval(update, 5000);
	});
</script>
