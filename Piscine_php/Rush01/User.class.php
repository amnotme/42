<?php
	class User {
		private $_login;
		private $_passwd;

		public $wins = 0;
		public $losses = 0;

		public function getLogin(): String { return ($this->_login); }

		public function updatePass(String $passwd) {
			$this->_passwd = hash("sha256", $passwd);
		}

		public function auth(String $passwd): bool {
			return ($this->_passwd == hash("sha256", $passwd));
		}

		public function __toString() {
			return ($this->_login);
		}

		public function __construct(String $login, String $passwd) {
			$this->_passwd = hash("sha256", $passwd);
			$this->_login = $login;
		}
	}
?>
