<?php
	require_once("Game.class.php");

	function session_lock() {
		$mutex = fopen($_SERVER['DOCUMENT_ROOT']."/database/games.db", "a+");
		flock($mutex, LOCK_EX);
		return ($mutex);
	}

	function session_unlock($mutex) {
		flock($mutex, LOCK_UN);
		fclose($mutex);
	}

	function game_session_save($id, Game $game) {
		$mutex = session_lock();

		if (file_exists($_SERVER['DOCUMENT_ROOT']."/database/games.db")) {
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/games.db"));
			$db[$id] = $game;
			file_put_contents($_SERVER['DOCUMENT_ROOT']."/database/games.db", serialize($db));
		}

		session_unlock($mutex);
	}

	function game_session($id) {
		$mutex = session_lock();

		if (file_exists($_SERVER['DOCUMENT_ROOT']."/database/games.db")) {
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/games.db"));

			if ($db !== false && array_key_exists($id, $db)) {
				session_unlock($mutex);
				return ($db[$id]);
			}
		}

		session_unlock($mutex);
		return (false);
	}

	function game_session_clear($id) {
		$mutex = session_lock();

		if (file_exists($_SERVER['DOCUMENT_ROOT']."/database/games.db")) {
			$db = unserialize(file_get_contents($_SERVER['DOCUMENT_ROOT']."/database/games.db"));

			if ($db !== false && array_key_exists($id, $db))
				unset($db[$id]);
		}

		session_unlock($mutex);
		return (false);
	}
?>