<?php
require_once("Ship.class.php");
require_once("Game.class.php");

class StarLight extends ship {
	public function getName(): String {
		return ("Star Light");
	}

	public function getPP(): int {
		return (22);
	}
	
	public function getHP(): int {
		return (15);
	}

	public function getBaseSpeed(): int {
		return (20);
	}

	public function getHandling(): int {
		return (8);
	}

	public function getBaseDefense(): int {
		return (-1);
	}

	public function getBaseAttack(): int {
		return (5);
	}

	public function shoot() {
		$this->_fireBullet(12, $this->getBaseAttack(), true, 0);
	}

	public function __construct(Game $game, int $player) {
		parent::__construct($game, $player, 5, 1, array(
			array(
				"images/light/image_part_001.png",
				"images/light/image_part_002.png",
				"images/light/image_part_003.png",
				"images/light/image_part_004.png",
				"images/light/image_part_005.png"
			)
		));
	}
}
?>
