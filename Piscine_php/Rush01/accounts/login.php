<?php
	require_once("auth.php");

	$error = false;
	if (array_key_exists("login", $_POST) &&
		array_key_exists("passwd", $_POST) &&
		auth($_POST["login"], $_POST["passwd"]) !== false) {
		if (!save_session($_POST["login"], $_POST["passwd"]))
			$error = "Session error!";
	}
	else
		$error = "Invalid login or password!";

	if ($error !== false)
		header("Location: ../sign_in.php?alert=".$error);
	else
		header("Location: ../index.php");
?>
