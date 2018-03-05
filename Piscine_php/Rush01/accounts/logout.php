<?php
	if (session_start())
		$_SESSION["rush01_token"] = "";
	header("Location: ../index.php");
?>