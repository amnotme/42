<?php
	require_once("Cell.class.php");
	require_once("ShipFragment.class.php");
	require_once("Game.class.php");

	abstract class Ship {
		protected $_game;
		protected $_player;

		protected $_fragments;
		protected $_width;
		protected $_height;
		protected $_isPlaced;

		protected $_lastTurn;
		protected $_lockedTurn;
		protected $_hasOrdered;
		protected $_hasRotated;
		protected $_hasMoved;
		protected $_hasShot;

		protected $_rotation;
		protected $_distance;

		protected $_hp;
		protected $_pp;

		protected $_speedModifier;
		protected $_defenseModifier;
		protected $_attackModifier;

		protected $_collider;

		abstract function getName(): String;
		abstract function getHP(): int;
		abstract function getPP(): int;
		abstract function getBaseSpeed(): int;
		abstract function getHandling(): int;
		abstract function getBaseDefense(): int;
		abstract function getBaseAttack(): int;
		abstract function shoot();

		public function dealDamage(int $damage) {
			$damage -= $this->_defenseModifier;
			if ($damage >= $this->_hp)
				$this->destroy();
			else
				$this->_hp -= $damage;
		}

		public function getRotation() { return $this->_rotation; }
		public function getPlayer() { return $this->_player; }

		public function getWidth(): int { return ($this->_width); }
		public function getHeight(): int { return ($this->_height); }

		public function getRemainingHP(): int { return ($this->_hp); }
		public function getRemainingPP(): int { return ($this->_pp); }

		public function increaseSpeed(): bool {
			if ($this->_pp < 1)
				return (false);
			$this->_pp -= 1;
			$this->_speedModifier += $this->_game->rollDice(1);
			return (true);
		}

		public function getSpeedModifier(): int { return ($this->_speedModifier); }

		public function getSpeed(): int {
			return ($this->_speedModifier + $this->getBaseSpeed());
		}

		public function getHandlingFactor(): int {
			return ($this->_distance);
		}

		public function increaseDefense(): bool {
			if ($this->_pp < 1)
				return (false);
			$this->_pp -= 1;
			$this->_defenseModifier++;
			return (true);
		}

		public function getDefenseModifier(): int { return ($this->_defenseModifier); }

		public function getDefense(): int {
			return ($this->_defenseModifier + $this->getBaseDefense());
		}

		public function increaseAttack(): bool {
			if ($this->_pp < 1)
				return (false);
			$this->_pp -= 1;
			$this->_attackModifier += $this->_game->rollDice(1);
			return (true);
		}

		public function getAttackModifier(): int { return ($this->_attackModifier); }

		public function getAttack(): int {
			return ($this->_attackModifier + $this->getBaseAttack());
		}

		protected function _fireBullet(int $maxDistance, int $damage, bool $friendlyFire, int $offset) {
			$coords = $this->_getBaseCoords();
			$x = $coords[0];
			$y = $coords[1];

			switch ($this->_rotation) {
				case 0:
					$x += $this->_width;
					$y += $offset;
					for ($i = 0; $i < $maxDistance; $i++) {
						if (($cell = $this->_game->get($x + $i, $y)) != null) {
							if ($cell instanceof ShipFragment) {
								if ($friendlyFire || $cell->getShip()->_player != $this->_player)
									$cell->getShip()->dealDamage($damage);
							}
							break;
						}
					}
					break;

				case 1:
					$y += $this->_width;
					$x += $offset;
					for ($i = 0; $i < $maxDistance; $i++) {
						if (($cell = $this->_game->get($x, $y + $i)) != null) {
							if ($cell instanceof ShipFragment) {
								if ($friendlyFire || $cell->getShip()->_player != $this->_player)
									$cell->getShip()->dealDamage($damage);
							}
							break;
						}
					}
					break;

				case 2:
					$x -= $this->_width;
					$y -= $offset;
					for ($i = 0; $i < $maxDistance; $i++) {
						if (($cell = $this->_game->get($x - $i, $y)) != null) {
							if ($cell instanceof ShipFragment) {
								if ($friendlyFire || $cell->getShip()->_player != $this->_player)
									$cell->getShip()->dealDamage($damage);
							}
							break;
						}
					}
					break;

				case 3:
					$y -= $this->_width;
					$x -= $offset;
					for ($i = 0; $i < $maxDistance; $i++) {
						if (($cell = $this->_game->get($x, $y - $i)) != null) {
							if ($cell instanceof ShipFragment) {
								if ($friendlyFire || $cell->getShip()->_player != $this->_player)
									$cell->getShip()->dealDamage($damage);
							}
							break;
						}
					}
					break;
			}
		}

		public function getCellID(): String {
			return ("{$this->_fragments[0][0]->x}x{$this->_fragments[0][0]->y}");
		}

		protected function _generatePostJS(array $posts): String {
			$JS = "\$.post(\"\", {";
			$JS .= "'cell_id': cell_id";

			foreach ($posts as $key => $value)
				$JS .= ", ".$key.": \"".$value."\"";

			$JS .= "}, function(data) { update(); });";
			return ($JS);
		}

		public function onClickJS(array &$grid): String {
			$state = $this->_game->getState();
			if ($state["ship"] == null && $state["player"] == $this->_player && $this->canActivate())
				return ($this->_generatePostJS(array("ship_action" => "ACTIVATE")));
			else
				return ("");
		}

		public function onPost(array &$grid) {
			$state = $this->_game->getState();
			if ($state["player"] != $this->_player)
				return;

			if ($state["turn"] > $this->_lastTurn) {
				$this->_lastTurn = $state["turn"];
				$this->_hasOrdered = false;

				if ($state["turn"] <= $this->_lockedTurn) {
					$this->_hasRotated = true;
					$this->_hasMoved = true;
					$this->_hasShot = true;
				}
				else {
					$this->_hasRotated = false;
					$this->_hasMoved = false;
					$this->_hasShot = false;
				}

				$this->_speedModifier = 0;
				$this->_defenseModifier = 0;
				$this->_attackModifier = 0;
				$this->_pp = $this->getPP();
			}

			if (array_key_exists("ship_action", $_POST)) {
				switch ($_POST["ship_action"]) {
					case "ACTIVATE":
						$this->_game->activate($this);
						break;

					case "INCREASE SPEED (1PP)":
						if ($state["phase"] == 0 && $state["ship"] === $this)
							$this->increaseSpeed();
						break;

					case "INCREASE DEFENSE (1PP)":
						if ($state["phase"] == 0 && $state["ship"] === $this)
							$this->increaseDefense();
						break;

					case "INCREASE ATTACK (1PP)":
						if ($state["phase"] == 0 && $state["ship"] === $this)
							$this->increaseAttack();
						break;

					case "COMPLETE ORDER":
						if ($state["phase"] == 0 && $state["ship"] === $this) {
							$this->_hasOrdered = true;
							$this->_game->deactivate();
						}
						break;

					case "ROTATE LEFT":
						if ($state["phase"] == 1 && $state["ship"] === $this && $this->canRotate()) {
							$this->rotateLeft();
							$this->_hasRotated = true;
						}
						break;

					case "ROTATE RIGHT":
						if ($state["phase"] == 1 && $state["ship"] === $this && $this->canRotate()) {
							$this->rotateRight();
							$this->_hasRotated = true;
						}
						break;

					case "MOVE":
						if ($state["phase"] == 1 && $state["ship"] === $this && array_key_exists("distance", $_POST)) {
							$this->move((int)$_POST["distance"]);
							$this->_hasMoved = true;
							$this->_game->deactivate();
						}
						break;

					case "FIRE":
						if ($state["phase"] == 2 && $state["ship"] === $this) {
							$this->shoot();
							$this->_hasShot = true;
							$this->_game->deactivate();
						}
						break;
				}
			}
		}

		public function canActivate(): bool {
			$state = $this->_game->getState();
			if ($state["turn"] == $this->_lastTurn) {
				switch ($state["phase"]) {
					case 0:
						return (!$this->_hasOrdered);

					case 1:
						return (!$this->_hasMoved);

					case 2:
						return (!$this->_hasShot);
				}
			}
			return (true);
		}

		public function place(array &$grid, int $x, int $y): bool {
			if (!$this->_isPlaced && $this->_checkSize($x, $y)) {
				$this->_isPlaced = true;
				$this->_moveShip($x, $y);
				return (true);
			}
			return (false);
		}

		public function includesFragment(Cell $fragment): bool {
			for ($i = 0; $i < $this->_height; $i++) {
				for ($j = 0; $j < $this->_width; $j++) {
					if ($fragment === $this->_fragments[$i][$j])
						return (true);
				}
			}
			return (false);
		}

		public function destroy() {
			for ($i = 0; $i < $this->_height; $i++) {
				$this->_fragments[] = array();
				for ($j = 0; $j < $this->_width; $j++)
					$this->_game->remove($this->_fragments[$i][$j]->x, $this->_fragments[$i][$j]->y);
			}

			$this->_hp = 0;
			if ($this->_game->getState()["ship"] === $this)
				$this->_game->deactivate();
		}

		public function _getBaseCoords(): array {
			if (!$this->_isPlaced)
				return (array(-1, -1));

			switch ($this->_rotation) {
				case 0:
					return (array($this->_fragments[0][0]->x, $this->_fragments[0][0]->y));

				case 1:
					return (array($this->_fragments[$this->_height - 1][0]->x, $this->_fragments[$this->_height - 1][0]->y));

				case 2:
					return (array($this->_fragments[$this->_height - 1][$this->_width - 1]->x, $this->_fragments[$this->_height - 1][$this->_width - 1]->y));

				case 3:
					return (array($this->_fragments[0][$this->_width - 1]->x, $this->_fragments[0][$this->_width - 1]->y));
			}
			return (array(-1, -1));
		}

		protected function _checkSize(int $x, int $y, $rotation = -1): bool {
			$gameWidth = $this->_game->getWidth();
			$gameHeight = $this->_game->getHeight();

			if ($x < 0 || $y < 0 || $x >= $gameWidth || $y >= $gameHeight) {
				$this->_collider = null;
				return (false);
			}

			if (!is_numeric($rotation) || $rotation < 0 || $rotation > 3)
				$rotation = $this->_rotation;

			$grid = $this->_game->getGrid();
			switch ($rotation) {
				case 0:
				case 2:
					if ($x + $this->_width > $gameWidth || $y + $this->_height > $gameHeight) {
						$this->_collider = null;
						return (false);
					}

					for ($i = 0; $i < $this->_height; $i++) {
						for ($j = 0; $j < $this->_width; $j++) {
							if ($grid[$y + $i][$x + $j] != null && !($this->includesFragment($grid[$y + $i][$x + $j]))) {
								$this->_collider = $grid[$y + $i][$x + $j];
								return (false);
							}
						}
					}
					break;

				case 1:
				case 3:
					if ($x + $this->_height >= $gameWidth || $y + $this->_width >= $gameHeight) {
						$this->_collider = null;
						return (false);
					}

					for ($i = 0; $i < $this->_width; $i++) {
						for ($j = 0; $j < $this->_height; $j++) {
							if ($grid[$y + $i][$x + $j] != null && !($this->includesFragment($grid[$y + $i][$x + $j]))) {
								$this->_collider = $grid[$y + $i][$x + $j];
								return (false);
							}
						}
					}
					break;
			}
			return (true);
		}

		protected function _moveShip(int $x, int $y): bool {
			if (!$this->_isPlaced || !($this->_checkSize($x, $y)))
				return (false);

			for ($i = 0; $i < $this->_height; $i++) {
				for ($j = 0; $j < $this->_width; $j++)
					$this->_game->remove($this->_fragments[$i][$j]->x, $this->_fragments[$i][$j]->y);
			}

			switch ($this->_rotation) {
				case 0:
					for ($i = 0; $i < $this->_height; $i++) {
						for ($j = 0; $j < $this->_width; $j++)
							$this->_game->place($x + $j, $y + $i, $this->_fragments[$i][$j]);
					}
					break;

				case 1:
					for ($i = 0; $i < $this->_width; $i++) {
						for ($j = 0; $j < $this->_height; $j++)
							$this->_game->place($x + $j, $y + $i, $this->_fragments[$this->_height - $j - 1][$i]);
					}
					break;

				case 2:
					for ($i = 0; $i < $this->_height; $i++) {
						for ($j = 0; $j < $this->_width; $j++)
							$this->_game->place($x + $j, $y + $i, $this->_fragments[$this->_height - $i - 1][$this->_width - $j - 1]);
					}
					break;

				case 3:
					for ($i = 0; $i < $this->_width; $i++) {
						for ($j = 0; $j < $this->_height; $j++)
							$this->_game->place($x + $j, $y + $i, $this->_fragments[$j][$this->_width - $i - 1]);
					}
					break;
			}
			return (true);
		}

		public function isStationary(): bool {
			return ($this->_distance > $this->getHandling() || $this->_distance == 0);
		}

		public function canRotate(): bool {
			return (!$this->_hasRotated && $this->isStationary());
		}

		public function move(int $distance) {
			if ($distance == 0 || $distance > $this->getSpeed())
				$distance = $this->getSpeed();

			$coords = $this->_getBaseCoords();
			$x = $coords[0];
			$y = $coords[1];
			$this->_distance += $distance;

			switch ($this->_rotation) {
				case 0:
					while ($distance--) {
						if (!($this->_moveShip(++$x, $y))) {
							if ($this->_collider instanceof ShipFragment) {
								if ($distance > 0) {
									$damage = $this->_collider->getShip()->getHP();
									$this->_collider->getShip()->dealDamage($damage);
									$this->dealDamage($damage);
								}
								$this->_lockedTurn = $this->_game->getState()["turn"] + 1;
								$this->_distance = 0;
							}
							else
								$this->destroy();
							break;
						}
					}
					break;

				case 1:
					while ($distance--) {
						if (!($this->_moveShip($x, ++$y))) {
							if ($this->_collider instanceof ShipFragment) {
								if ($distance > 0) {
									$damage = $this->_collider->getShip()->getHP();
									$this->_collider->getShip()->dealDamage($damage);
									$this->dealDamage($damage);
								}
								$this->_lockedTurn = $this->_game->getState()["turn"] + 1;
								$this->_distance = 0;
							}
							else
								$this->destroy();
							break;
						}
					}
					break;

				case 2:
					while ($distance--) {
						if (!($this->_moveShip(--$x, $y))) {
							if ($this->_collider instanceof ShipFragment) {
								if ($distance > 0) {
									$damage = $this->_collider->getShip()->getHP();
									$this->_collider->getShip()->dealDamage($damage);
									$this->dealDamage($damage);
								}
								$this->_lockedTurn = $this->_game->getState()["turn"] + 1;
								$this->_distance = 0;
							}
							else
								$this->destroy();
							break;
						}
					}
					break;

				case 3:
					while ($distance--) {
						if (!($this->_moveShip($x, --$y))) {
							if ($this->_collider instanceof ShipFragment) {
								if ($distance > 0) {
									$damage = $this->_collider->getShip()->getHP();
									$this->_collider->getShip()->dealDamage($damage);
									$this->dealDamage($damage);
								}
								$this->_lockedTurn = $this->_game->getState()["turn"] + 1;
								$this->_distance = 0;
							}
							else
								$this->destroy();
							break;
						}
					}
					break;
			}
		}

		public function rotateLeft() {
			$rotation = $this->_rotation;
			$rotation--;
			if ($rotation < 0)
				$rotation = 3;

			if (!$this->_isPlaced) {
				for ($i = 0; $i < $this->_height; $i++) {
					for ($j = 0; $j < $this->_width; $j++)
						$this->_fragments[$i][$j]->rotateLeft();
				}

				$this->_rotation = $rotation;
				$this->_distance = 0;
				return;
			}

			$coords = $this->_getBaseCoords();
			$x = $coords[0];
			$y = $coords[1];

			if ($this->_checkSize($x, $y, $rotation) && $this->canRotate()) {
				for ($i = 0; $i < $this->_height; $i++) {
					for ($j = 0; $j < $this->_width; $j++)
						$this->_fragments[$i][$j]->rotateLeft();
				}

				$this->_rotation = $rotation;
				$this->_moveShip($x + $this->_width/2 - ($this->_width % 2 == 0 ? 1 : 0), $y - $this->_height - 1);
				$this->_distance = 0;
			}
		}

		public function rotateRight() {
			$rotation = $this->_rotation;
			$rotation++;
			if ($rotation > 3)
				$rotation = 0;

			if (!$this->_isPlaced) {
				for ($i = 0; $i < $this->_height; $i++) {
					for ($j = 0; $j < $this->_width; $j++)
						$this->_fragments[$i][$j]->rotateRight();
				}

				$this->_rotation = $rotation;
				$this->_distance = 0;
				return;
			}

			$coords = $this->_getBaseCoords();
			$x = $coords[0];
			$y = $coords[1];

			if ($this->_checkSize($x, $y, $rotation) && $this->canRotate()) {
				for ($i = 0; $i < $this->_height; $i++) {
					for ($j = 0; $j < $this->_width; $j++)
						$this->_fragments[$i][$j]->rotateRight();
				}

				$this->_rotation = $rotation;
				$this->_moveShip($x + $this->_width / 2 - ($this->_width % 2 == 0 ? 2: 0) , $y - $this->_height - 1);
				$this->_distance = 0;
			}
		}

		public function __construct(Game $game, int $player, int $width, int $height, array $icons) {
			if ($height < 1 || $width < 1)
				throw new Exception ("Ship::__construct() => Ship size too small!");

			$this->_game = $game;
			$this->_player = $player;

			$this->_width = $width;
			$this->_height = $height;

			$this->_fragments = array();
			for ($i = 0; $i < $height; $i++) {
				$this->_fragments[] = array();
				for ($j = 0; $j < $width; $j++)
					$this->_fragments[$i][] = new ShipFragment($this, $icons[$i][$j]);
			}

			$this->_isPlaced = false;

			$this->_lastTurn = -1;
			$this->_lockedTurn = -1;
			$this->_hasOrdered = false;
			$this->_hasRotated = false;
			$this->_hasMoved = false;
			$this->_hasShot = false;

			$this->_rotation = 0;
			$this->_distance = 0;

			$this->_hp = $this->getHP();
			$this->_pp = $this->getPP();

			$this->_speedModifier = 0;
			$this->_defenseModifier = 0;
			$this->_attackModifier = 0;
		}
	}
?>
