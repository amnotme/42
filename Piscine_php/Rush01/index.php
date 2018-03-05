<?php
  if (session_start() === false)
    header("Location: ./sign_in.php");
?>
<html lang="en">
<head>
	<link rel="stylesheet" href="index.css" type="text/css"/>
  <meta charset="UTF-8" />
  <title>Battle.net Launcher</title>
  <script>
  </script>
</head>
<body>
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
	<script type="text/javascript" src="index.js"></script>
  <div id="resizable" class="wrap sc2">
    <div class="filter sc2blur"></div>
    <header role="banner">
      <div class="logo">
        <div class="hover">Click me</div>
      </div>
      <nav role='navigation'>
        <ul>
          <li><a href="#/Games" class="active" id="games">Game</a></li>
		  <li>
 				<div class="dropdown">
 					<div class="textbtn"></div>
 					<div class="dropdown-content">
 						<a href="change_pass.php">Change Password</a>
 						<a href="#">Delete Account</a>
 					</div>
 				</div>
 			</li>
					<li><a href="#/Account" id="Account">ACCOUNT</a></li>
 					<li><a href="sign_in.php" id="logout">LOGOUT</a></li>
			<li><a href="/Chat" id="chat">Chat(Uses your login)</a></li>
      </nav>
      <div class="login">
        <div class="left"></div>
        <div class="right"></div>
      </div>
    </header>
    <div class="wrap-games active">
      <div class="flex">
        <aside class="slide">
          <div id="sortable" class="item-wrap">
		 	<div class="item sc2 active">
				<div class="icon sc2"></div>
			 	<p>Servers</p>
			</div>
            <div class="item hs">
              <div class="icon hs"></div>
              <p>Leaderboards</p>
            </div>
            <div class="item ip">
              <div class="icon ip"></div>
              <p>Stats</p>
            </div>
          </div>>
        </aside>
        <section role="content">
          <div class="loader"></div>
          <div class="game-wrap slide">

            <div class="sc2container active">
              <div class="logo sc2lo"></div>
              <div class="flex">
                <div class="box1 maxstyle">
                  <h2>Servers</h2>
				  <input type="button" id="refserver" type="refresh" value="RE"></input>
                  <hr />
				  <div id="servers">
				  </div>
				  <div id="server-botton">
					  <input id="servbutt" type="submit" disabled="disabled" value="Join"></input>
				  </div>
                </div>

                <div class="box2">
                  <div class="content-wrap">
                    <h2>Server Info</h2>
					<hr style="border-color: rgba(255, 255, 255, 0.5);"/>
                  </div>
				  <div id="serinfo">
				  </div>
                </div>
                <div class="box2">
                  <div class="content-wrap">
                    <h2>Players</h2>
					<hr style="border-color: rgba(255, 255, 255, 0.5);" />
					<div id="servplayers">
					</div>
                  </div>
                </div>
              </div>
              <div class="bottom">
				<div class="box1-A">
				  <h2>Create Server</h2>
				  <hr />
				  <form class="creategame">
					<fieldset>
	  				Server Name:<br>
	  				<input type="text" name="s_name" value=""><br>
	  				Server Info:<br>
	  				<input type="text" name="s_info" value=""><br><br>
					Max.players:<br>
					<input type="text" name="max_num" value=""><br><br>
	  				<input type="text" name="action" value="createserver" hidden>
	  				<input type="submit" value="Submit">
					</fieldset>
  				  </form>
				</div>
              </div>
            </div>

            <div class="hscontainer">
              <div class="logo hslo"></div>
              <div class="flex">
                <div class="box1">
                  <h2>Leaderboards</h2>
                  <hr />
                  <div class="content-wrap">
					  <table>
						  <tr style="color: white">
							  <td>Players</td>
							  <td>Wins</td>
							  <td>Losses</td>
						  </tr>
					  </table>
                  </div>
                </div>
              </div>
            </div>


            <div class="ipcontainer">
              <div class="logo iplo"></div>
              <div class="flex">
                <div class="box1">
                  <h2>STATS</h2>
                  <hr />
                  <div class="content-wrap">
					<div id="ip">
					</div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </section>
      </div>
    </div>
  </div>
</body>
</html>
