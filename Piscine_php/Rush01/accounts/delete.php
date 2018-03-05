<?php
	require_once("auth.php");
	require_once($_SERVER['DOCUMENT_ROOT']."/User.class.php");

	$error = false;
	$user = retrieve_session();

	if ($user !== false) {
		$mutex = mutex_lock();

		if ($user->getLogin() != "root" && file_exists($_SERVER['DOCUMENT_ROOT']."/database/users.db")) {
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db"));
			unset($db[$user->getLogin()]);
			file_put_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db", serialize($db));
		}

		mutex_unlock($mutex);
	}

	if ($user === false)
		header("Location: ../index.php");
	else
		header("Location: ../sign_in.php?alert=Account deleted!");
?>