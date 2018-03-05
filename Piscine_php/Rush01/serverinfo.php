<?php
	include 'User.class.php';
	include 'Game.class.php';
	include 'gamedata.php';
	include './accounts/auth.php';

	$user = retrieve_session();
	$dbh = new PDO('mysql:dbname=rush01;host=127.0.0.1;port=8889', 'root', 'root');
	switch ($_REQUEST['action']) {
		case 'servers':
			$server_sql = "SELECT id, name FROM games WHERE status='pending'";
			$res = $dbh->query($server_sql);
			header('Content-type: application/json');
			echo json_encode($res->fetchAll(PDO::FETCH_ASSOC));
			break;
		case 'server':
			$id = $_GET['id'];
			$server_sql = "SELECT id, name, metadata, max_number FROM games WHERE id = ?";
			$users_sql = "SELECT login FROM game_user WHERE game_id = ?";
			$pre = $dbh->prepare($server_sql);
			$pre->execute(array($id));
			$preu = $dbh->prepare($users_sql);
			$preu->execute(array($id));
			header('Content-type: application/json');
			echo json_encode(array(
					"servinfo" => $pre->fetch(PDO::FETCH_ASSOC),
					"users" => $preu->fetchAll(PDO::FETCH_ASSOC)
				)
			);
			break;
		case 'leaderboard':
			$mutex = mutex_lock();
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db"));
			mutex_unlock($mutex);
			$users = array();
			foreach ($db as $value) {
				$users[] = array(
					"login" => $value->getLogin(),
					"wins" => $value->wins,
					"loses" => $value->losses
				);
			}
			header('Content-type: application/json');
			echo json_encode($users);
			break;
		case 'ip':
			header('Content-type: application/json');
			echo json_encode(array("login" => $user->getLogin(), "wins" => $user->wins, "loses" => $user->losses));
			break;
		case 'createserver':
			$name = $_POST['s_name'];
			$info = $_POST['s_info'];
			$u = $user->getLogin();
			$max_num = $_POST['max_num'];
			$user_sql = "INSERT INTO games(user, name, metadata, max_number, status) VALUES (?, ?, ?, ?, ?, 'pending')";
			$pre = $dbh->prepare($user_sql);
			$pre->execute(array($u, $name, $info, $max_num));
			header('Content-type: application/json');
			echo json_encode(array("row" => $pre->rowCount()));
			break;
		case 'servjoin':
			$u = $user->getLogin();
			$id = $_POST['id'];
			$user_sql = "INSERT INTO game_user(login, game_id) VALUES ('$u', '$id')";
			$res = $dbh->query($user_sql);
			$gamedata = "SELECT COUNT(1) as count FROM game_user WHERE game_id = ?";
			$pre = $dbh->prepare($gamedata);
			$pre->execute(array($id));
			$gamed = $pre->fetch(PDO::FETCH_ASSOC);
			header('Content-type: application/json');
			echo json_encode(array("row" => $gamed['count']));
			break;
		case 'start':
			$id = $_POST['id'];
			start($id, $dbh);
			break;

		default:
			# code...
			break;
	}

	function start($id, $dbh) {
		$user_sql = "SELECT login FROM game_user WHERE game_id = ?";
		$pre = $dbh->prepare($user_sql);
		$pre->execute(array($id));
		$users = array();
		foreach ($pre->fetch(PDO::FETCH_ASSOC) as $value) {
			var_dump($value);
			$users[] = new User($value, 's');
		}die();
		$game = new Game($users, 150, 100);
		$game->populate(true);
		$sergame = base64_encode(serialize($game));
		$user_sql = "UPDATE games SET status = 'started' AND game = ? WHERE id = ?";
		$pre = $dbh->prepare($user_sql);
		$pre->execute(array($sergame, $id));
		game_session_save($id, $game);
		// header("Location: ./game.php?id={$id}");
	}

?>
