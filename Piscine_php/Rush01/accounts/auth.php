<?php
	require_once($_SERVER['DOCUMENT_ROOT']."/User.class.php");

	function mutex_lock() {
		$mutex = fopen($_SERVER['DOCUMENT_ROOT']."/database/users.db", "a+");
		flock($mutex, LOCK_EX);
		return ($mutex);
	}

	function mutex_unlock($mutex) {
		flock($mutex, LOCK_UN);
		fclose($mutex);
	}

	function auth($login, $passwd) {
		$mutex = mutex_lock();

		if ($login != "" && $passwd != "" && file_exists($_SERVER['DOCUMENT_ROOT']."/database/users.db")) {
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/users.db"));

			if ($db !== false && array_key_exists($login, $db) && $db[$login]->auth($passwd)) {
				mutex_unlock($mutex);
				return ($db[$login]);
			}
		}

		mutex_unlock($mutex);
		return (false);
	}

	function direct_auth($db, $login, $passwd) {
		if ($login != "" && $passwd != "") {
			if (array_key_exists($login, $db) && $db[$login]->auth($passwd))
				return (true);
		}
		return (false);
	}

	function save_session($login, $passwd) {
		if (session_start()) {
			$token = array();
			$token["login"] = $login;
			$token["passwd"] = $passwd;
			$_SESSION["rush01_token"] = base64_encode(serialize($token));
			return (true);
		}
		return (false);
	}

	function retrieve_session() {
		if (session_start() && array_key_exists("rush01_token", $_SESSION) && $_SESSION["rush01_token"] != "") {
			$token = unserialize(base64_decode($_SESSION["rush01_token"]));

			if ($token !== false)
				return (auth($token["login"], $token["passwd"]));
		}
		return (false);
	}
?>