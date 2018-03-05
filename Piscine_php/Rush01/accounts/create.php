<?php
	require_once("auth.php");
	require_once($_SERVER['DOCUMENT_ROOT']."/User.class.php");

	$error = false;
	$db = false;
	if (array_key_exists("login", $_POST) && ($login = $_POST["login"]) != "" &&
		array_key_exists("passwd", $_POST) && ($passwd = $_POST["passwd"]) != "" &&
		array_key_exists("confpw", $_POST) && ($confpw = $_POST["confpw"]) != "") {

		if ($confpw == $passwd) {
			$mutex = mutex_lock();

			if (file_exists($_SERVER['DOCUMENT_ROOT']."/database/users.db"))
				$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db"));
			if ($db === false)
				$db = array();

			if (array_key_exists($login, $db))
				$error = "Account with that username already exists!";
			else {
				$db[$login] = new User($login, $passwd);
				file_put_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db", serialize($db));
			}

			mutex_unlock($mutex);
		}
		else
			$error = "Passwords did not match!";
	}
	else
		$error = "Please fill in all fields!";

	if ($error !== false)
		header("Location: ../sign_up.php?alert=".$error);
	else
		header("Location: ../sign_in.php?alert=Account created!");
?>