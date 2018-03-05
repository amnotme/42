<?php
	interface Cell {
		public function setX(int $x);
		public function setY(int $y);

		public function onClickJS(array &$grid): String;
		public function onPost(array &$grid);
		public function getTitle(): String;
		public function getIconURL(): String;
		public function getRotation(): String;
	}
?>
