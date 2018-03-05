<?php
require_once("Ship.class.php");
require_once("Game.class.php");

class StarDreadnaught extends Ship {
	public function getName(): String {
		return ("Star Dreadnaught");
	}

	public function getPP(): int {
		return (15);
	}

	public function getHP(): int {
		return (25);
	}

	public function getBaseSpeed(): int {
			return (10);
		}

	public function getHandling(): int {
		return (2);
	}

	public function getBaseDefense(): int {
		return (3);
	}

	public function getBaseAttack(): int {
		return (7);
	}

	public function shoot() {
		$this->fireBullet(7, $this->getAttack(), true, 0);
		$this->fireBullet(7, $this->getAttack(), true, 1);
		$this->fireBullet(7, $this->getAttack(), true, 2);
	}

	public function __construct(Game $game, int $player) {
		parent::__construct($game, $player, 10, 3, array(
			array(
				"images/dreadnaught/image_part_001.png",
				"images/dreadnaught/image_part_002.png",
				"images/dreadnaught/image_part_003.png",
				"images/dreadnaught/image_part_004.png",
				"images/dreadnaught/image_part_005.png",
				"images/dreadnaught/image_part_006.png",
				"images/dreadnaught/image_part_007.png",
				"images/dreadnaught/image_part_008.png",
				"images/dreadnaught/image_part_009.png",
				"images/dreadnaught/image_part_010.png"),
			array(
				"images/dreadnaught/image_part_011.png",
				"images/dreadnaught/image_part_012.png",
				"images/dreadnaught/image_part_013.png",
				"images/dreadnaught/image_part_014.png",
				"images/dreadnaught/image_part_015.png",
				"images/dreadnaught/image_part_016.png",
				"images/dreadnaught/image_part_017.png",
				"images/dreadnaught/image_part_018.png",
				"images/dreadnaught/image_part_019.png",
				"images/dreadnaught/image_part_020.png"),
			array(
				"images/dreadnaught/image_part_021.png",
				"images/dreadnaught/image_part_022.png",
				"images/dreadnaught/image_part_023.png",
				"images/dreadnaught/image_part_024.png",
				"images/dreadnaught/image_part_025.png",
				"images/dreadnaught/image_part_026.png",
				"images/dreadnaught/image_part_027.png",
				"images/dreadnaught/image_part_028.png",
				"images/dreadnaught/image_part_029.png",
				"images/dreadnaught/image_part_030.png")
			
		));
	}
}
?>
