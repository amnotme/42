<?php
	require_once("Ship.class.php");
	require_once("Game.class.php");

	class StarShadow extends Ship {
		public function getName(): String {
			return ("Star Shadow");
		}

		public function getPP(): int {
			return (18);
		}

		public function getHP(): int {
			return (20);
		}

		public function getBaseSpeed(): int {
			return (10);
		}

		public function getHandling(): int {
			return (5);
		}

		public function getBaseDefense(): int {
			return (1);
		}

		public function getBaseAttack(): int {
			return (9);
		}

		public function shoot() {
			$this->_fireBullet(10, $this->getBaseAttack(), true, 0);
			$this->_fireBullet(10, $this->getBaseAttack(), true, 1);
		}

		public function __construct(Game $game, int $player) {
			parent::__construct($game, $player, 7, 2, array(
				array(
					"images/shadow/image_part_001.png",
					"images/shadow/image_part_002.png",
					"images/shadow/image_part_003.png",
					"images/shadow/image_part_004.png",
					"images/shadow/image_part_005.png",
					"images/shadow/image_part_006.png",
					"images/shadow/image_part_007.png"),
				array(
					"images/shadow/image_part_008.png",
					"images/shadow/image_part_009.png",
					"images/shadow/image_part_010.png",
					"images/shadow/image_part_011.png",
					"images/shadow/image_part_012.png",
					"images/shadow/image_part_013.png",
					"images/shadow/image_part_014.png")
			));
		}
	}
?>
