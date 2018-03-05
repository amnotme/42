<?php
	if (array_key_exists("alert", $_GET)) {
		echo ("<script>");
		echo ("\talert(\"".$_GET["alert"]."\");");
		echo ("</script>");
	}
?>

<head>
	<title>Change Password</title>
	<link rel="stylesheet" media="all" href="https://signin.intra.42.fr/assets/application-863befd8d8eb705f4cbc5a31f484c8d6c3c44ee946dea969c5d92d9a0344db15.css">
	<style>
		body{
		background: linear-gradient(#0000, CadetBlue), url("https://signin.intra.42.fr/assets/background_login-a4e0666f73c02f025f590b474b394fd86e1cae20e95261a6e4862c2d0faa1b04.jpg");
		}
		.img42{
			position: absolute;
			width: 12%;
    	height: 12%;
    	left: 42%;
    	top: 2%;
		}
		.h1font{
			position: absolute;
			font-family: sans-serif;
			color: white;
			font-size: 1.85vh;
			top: 10vh;
			left: 49%;
			padding-left: .355%;
			margin-top: 1.95vh;
		}
	</style>
</head>
<body>
	<div>
        <img src= "https://signin.intra.42.fr/assets/42_logo-7dfc9110a5319a308863b96bda33cea995046d1731cebb735e41b16255106c12.svg" class="img42">
        <h1 class = "h1font">Battlenet<h1>
  </div>
	<div class="page-sidebar left-main-container page-sidebar-fixed-left under-main-navbar">
	</div>
		<div class="login-page page-content page-content-fluid" data-turbolinks-scaffold="">
			<div class="row">
				<div class="main-top-menu">
				</div>
				<div class="col-lg-12">
					<div class="login-container">
						<div class="login-logo">
						</div>
						<div class="login-title">
							<h2>
								<span class="icon-lock">
								</span>
								Change Password
							</h2>
						</div>
						<div class="login-between">
						</div>
						<div class="login-main">
							<form class="simple_form form-horizontal new_user" action="accounts/modif.php" method="post">
								<div class="form-inputs">
									<div class="input-login login-input-group string optional user_login">
										<input class="login-control string optional" autofocus="autofocus" placeholder="Password" type="password" name="oldpw">
									</div>
									<div class="input-login login-input-group password optional user_password">
										<input class="login-control password optional" placeholder="New Password" type="password" name="newpw">
									</div>
									<div class="input-login login-input-group password optional user_password">
										<input class="login-control password optional" placeholder="Confirm New Password" type="password" name="confpw">
									</div>
								</div>
								<div class="form-actions">
									<input class="btn btn-login" name="commit" type="submit" value="Submit">
								</div>
							</form>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</body>
