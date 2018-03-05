<?php
	include '../User.class.php';
	include '../accounts/auth.php';
	$user = retrieve_session();
	if (!isset($user) || !$user)
		header('Location: http://localhost:8102/');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Battlenet Chat</title>
	<link rel="stylesheet" href="../index.css" type="text/css"/>
    <link rel="stylesheet" href="style.css" type="text/css" />
    <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>
    <script type="text/javascript" src="chat.js"></script>
    <script type="text/javascript">
      var name = prompt("Enter your chat name:", '<?= $user->getLogin() ?>');
    	if (!name || name === ' ') {
    	   name = "Guest";
    	}
    	name = name.replace(/(<([^>]+)>)/ig,"");
    	$("#name-area").html("You are: <span>" + name + "</span>");
        var chat =  new Chat();
    	$(function() {
    		 chat.getState();
             $("#sendie").keydown(function(event) {
                 var key = event.which;
                 if (key >= 33) {
                     var maxLength = $(this).attr("maxlength");
                     var length = this.value.length;
                     if (length >= maxLength) {
                         event.preventDefault();
                     }
                  }
                });
    		 $('#sendie').keyup(function(e) {
    			  if (e.keyCode == 13) {
            var text = $(this).val();
    				var maxLength = $(this).attr("maxlength");
            var length = text.length;
              if (length <= maxLength + 1) {
    			        chat.send(text, name);
    			        $(this).val("");
              }
              else {
    					$(this).val(text.substring(0, maxLength));
    				  }
    			  }
          });
    	});
    </script>
</head>
<body onload="setInterval('chat.update()', 1000)">
	<div id="resizable" class="wrap sc2">
	  	<div class="filter sc2blur"></div>
		<header role="banner">
		  <div class="logo">
			<div class="hover">Click me</div>
		  </div>
		  <nav role='navigation'>
			<ul>
			  	<li><a href="/#Games" id="games">Game</a></li>
				<li><a href="sign_in.php" id="logout">LOGOUT</a></li>
				<li><a href="/Chat" class="active" id="chat">Chat(Uses your login)</a></li>
			</ul>
		  </nav>
		  <div class="login">
			<div class="left"></div>
			<div class="right"></div>
		  </div>
		</header>
	</div>
    <div id="page-wrap">
        <h2>Battlenet Chat</h2>
        <p id="name-area"></p>
        <div id="chat-wrap">
          <div id="chat-area">
          </div>
        </div>
        <form id="send-message-area">
            <p>Trash Talk: </p>
            <textarea id="sendie" maxlength = '100' ></textarea>
        </form>
    </div>
</body>
</html>
