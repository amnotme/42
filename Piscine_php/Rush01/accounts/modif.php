<?php
	require_once("auth.php");
	require_once($_SERVER['DOCUMENT_ROOT']."/User.class.php");

	$error = false;
	$user = retrieve_session();
	if ($user !== false && array_key_exists("oldpw", $_POST) &&
		array_key_exists("newpw", $_POST) && array_key_exists("confpw", $_POST)) {
		$mutex = mutex_lock();

		if (file_exists($_SERVER['DOCUMENT_ROOT']."/database/users.db")) {
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db"));


			$oldpw = $_POST["oldpw"];
			if (($newpw = $_POST["newpw"]) != "" && $db !== false && direct_auth($db, $user->getLogin(), $oldpw)) {
				if ($newpw == $_POST["confpw"]) {
					$db[$user->getLogin()]->updatePass($newpw);
					save_session($user, $newpw);
					file_put_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db", serialize($db));
				}
				else
					$error = "Passwords did not match!";
			}
			else
				$error = "Invalid password!";
		}
		else
			$error = "No users in database!";

		mutex_unlock($mutex);
	}
	else if ($user === false)
		$error = "You must be logged in to change your password";
	else
		$error = "Bad submission!";

	if ($error !== false)
		header("Location: ../change_pass.php?alert=".$error);
	else
		header("Location: ../index.php");
?>