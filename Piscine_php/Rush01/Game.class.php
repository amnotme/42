<?php
	require_once("User.class.php");
	require_once("Cell.class.php");
	require_once("Obstacle.class.php");
	require_once("Ship.class.php");

	require_once("StarShadow.class.php");
	require_once("StarDreadnaught.class.php");
	require_once("StarLight.class.php");

	class Game {
		const COLORS = array(
			"#ffffff00",
			"#ff000040",
			"#00ff0040",
			"#0000ff40"
		);

		private $_state;
		private $_players;
		private $_ships;
		private $_width;
		private $_height;
		private $_grid;
		private $_isWaiting;

		public function getState(): array { return ($this->_state); }
		public function getPlayers(): array { return ($this->_players); }
		public function getWidth(): int { return ($this->_width); }
		public function getHeight(): int { return ($this->_height); }
		public function getGrid(): array { return ($this->_grid); }
		public function isWaiting(): bool { return ($this->_isWaiting); }

		public function join(User $user) {
			if ($this->_isWaiting && sizeof($this->_players) < 4)
				$this->_players[] = $user;
		}

		public function rollDice(int $numDice): int {
			$result = 0;
			for ($i = 0; $i < $numDice; $i++)
				$result += rand(1, 6);
			return ($result);
		}

		public function activate(Ship $ship) {
			if ($this->_state["ship"] == null && $ship->canActivate() && $ship->getRemainingHP() != 0) {
				$this->_state["ship"] = $ship;
				$this->_state["pp"] = $ship->getPP();
			}
		}

		public function deactivate() {
			$this->_state["ship"] = null;
			$this->_state["pp"] = 0;
		}

		public function place(int $x, int $y, Cell $object) {
			if ($x < $this->_width && $x >= 0 && $y < $this->_height && $y >= 0 && $this->_grid[$y][$x] == null) {
				$object->setX($x);
				$object->setY($y);
				$this->_grid[$y][$x] = $object;
			}
		}

		public function remove(int $x, int $y) {
			if ($x < $this->_width && $x >= 0 && $y < $this->_height && $y >= 0)
				$this->_grid[$y][$x] = null;
		}

		public function get(int $x, int $y) {
			if ($x < $this->_width && $x >= 0 && $y < $this->_height && $y >= 0)
				return ($this->_grid[$y][$x]);
			return (null);
		}

		public function getPhaseName(): String {
			switch ($this->_state["phase"]) {
				case 0:
					return ("Order");

				case 1:
					return ("Movement");

				case 2:
					return ("Shoot");
			}
			return ("Error");
		}

		public function generateJSPayload(): String {
			$JS = "";
			for ($i = 0; $i < $this->_height; $i++) {
				for ($j = 0; $j < $this->_width; $j++) {
					if ($this->_grid[$i][$j] != null) {
						$JS .= "function onClickCell_{$j}x{$i}() {\n";
						$JS .= "var cell_id = \"{$j}x{$i}\";\n";
						$JS .= $this->_grid[$i][$j]->onClickJS($this->_grid);
						$JS .= "\n}\n\n";
					}
				}
			}
			return ($JS);
		}

		public function generateBoard(): String {
			$obs_array = ['gaetan.png', 'meo.png', 'mlu.png', 'tony.png'];
			$board = "<table id=\"board\">\n";
			for ($i = 0; $i < $this->_height; $i++) {
				$board .= "<tr>\n";
				for ($j = 0; $j < $this->_width; $j++) {
					$obj = $this->_grid[$i][$j];
					$board .= "<td class='cell ";
					$board .= " ' ";
					if ($this->_grid[$i][$j] != null) {
						$board .= " title=\"".$this->_grid[$i][$j]->getTitle()."\"";
						$board .= " onclick=\"onClickCell_{$j}x{$i}()\">";
						if ($obj instanceOf Obstacle && $obj->isFace()) {
							$board .= "<img src='images/obstacles/" . $obs_array[rand(0, count($obs_array) - 1)] . "' ";
							$board .= "style='position: absolute; z-index: -1; "; 
							$board .= "width: " . ($obj->getWidth() * 44). "px; ";
							$board .= "height: " . ($obj->getHeight() * 45). "px; ";
							$board .= " ' />";
						}
						$board .= "<div  onclick=\"onClickCell_{$j}x{$i}()\" class=' ";
						if ($obj instanceOf ShipFragment)
						{
							$box = "imageBox" . $i . '-' . $j;
							$board .= $box; 

							$p = $obj->getShip()->getPlayer() + 1;
							$board .= " p{$p}_frag";
						}
						$board .= "'>";

						if ($obj instanceOf ShipFragment)
						{
							$board .= "<div onclick=\"onClickCell_{$j}x{$i}()\" class='imageInn'>";
						}

						$board .= "<img style='position:relative; z-index: -2;'";
						$board .= "class='rotate" . $this->_grid[$i][$j]->getRotation() . " ' ";
						
						$board .= "src='" . $this->_grid[$i][$j]->getIconURL() . "'/>";
						$board .= "</div>";
#						if ($obj instanceOf ShipFragment)
#						{
#							$board .= "<div class='hoverImg'>";
#							$board .= "<img src='images/orange.png' ";
##							$board .= "style='width:". (45*12) . "; height:" . (45*1) . " ' ";
#							$coords = $obj->getShip()->_getBaseCoords();
#							$x_max = $coords[0] + $obj->getShip()->getWidth();
#							$x_offset = $x_max - $j;
#							$y_max = $coords[1];
#							$y_offset = $y_max - $i;
#	#						$x = $coords[0] + $obj->getShip()->getWidth();
#	#						$y = $coords[1];
#	#						echo "x = $x, y = $y; i = $i, j = $j, x_offset = $x_offset\n";
#							$board .= "style='width:". (45*12) . "; height:" . (45*1) . " ' ";
#							$board .= " />";
#							$board .= "</div>";
#							$board .= "<style>";
#							$board .= "." . $box . " { position: relative; float: left;	}";
#							$board .= "." . $box . " .hoverImg { position: absolute; ";
#							$board .= "left: " . (45 * $x_offset) . "px; ";
#							$board .= "top: " . (45 * $y_offset) . "px; ";
#							$board .= "display: none; z-index: 2; opacity: 0.5; }";
#        					$board .= "." . $box . ":hover .hoverImg { display: block; }";
#							$board .= "</style>";
#						}


						$board .= "</td>";
					}
					else
						$board .= "/>\n";
				}
				$board .= "</tr>\n";
			}
			$board .= "</table>\n";
			return ($board);
		}

		public function generateLeft(): String {
			$td = "Turn: {$this->_state["turn"]}<br/>";
			$pnum = $this->_state["player"] + 1;
			$td .= "Player {$pnum}: ".$this->_players[$this->_state["player"]]."<br/>";

			if ($this->_state["ship"] != null) {
				$td .= "<br/>";
				$td .= "Active Ship: ".$this->_state["ship"]->getName()."<br/>";

				$td .= "\n<form method=\"post\"><input type=\"hidden\" name=\"cell_id\" value=\"".$this->_state["ship"]->getCellID()."\">";
				switch ($this->_state["phase"]) {
					case 0:
						$td .= "<input type=\"submit\" name=\"ship_action\" value=\"INCREASE SPEED (1PP)\"/><br/>";
						$td .= "<input type=\"submit\" name=\"ship_action\" value=\"INCREASE DEFENSE (1PP)\"/><br/>";
						$td .= "<input type=\"submit\" name=\"ship_action\" value=\"INCREASE ATTACK (1PP)\"/><br/>";
						$td .= "<input type=\"submit\" name=\"ship_action\" value=\"COMPLETE ORDER\"/>";
						break;

					case 1:
						if ($this->_state["ship"]->canRotate()) {
							$td .= "<input type=\"submit\" name=\"ship_action\" value=\"ROTATE LEFT\"/><br/>";
							$td .= "<input type=\"submit\" name=\"ship_action\" value=\"ROTATE RIGHT\"/><br/>";
						}
						$td .= "<input type=\"number\" name=\"distance\" min=\"1\" value=\"1\"/> ";
						$td .= "<input type=\"submit\" name=\"ship_action\" value=\"MOVE\"/>";
						break;

					case 2:
						$td .= "<br/><br/><br/>";
						$td .= "<input type=\"submit\" name=\"ship_action\" value=\"FIRE\"/>";
						break;
				}
				$td .= "</form>";
			}
			return ($td);
		}

		public function generateRight(): String {
			$td = "Current Phase: ".$this->getPhaseName()."<br/>";

			if ($this->_state["ship"] != null) {
				$td .= "<br/><br/>";
				$td .= "HP: {$this->_state["ship"]->getRemainingHP()}/{$this->_state["ship"]->getHP()}<br/>";
				$td .= "PP: {$this->_state["ship"]->getRemainingPP()}/{$this->_state["ship"]->getPP()}<br/>";
				$td .= "Speed: {$this->_state["ship"]->getBaseSpeed()} (+{$this->_state["ship"]->getSpeedModifier()})<br/>";
				$td .= "Defense: {$this->_state["ship"]->getBaseDefense()} (+{$this->_state["ship"]->getDefenseModifier()})<br/>";
				$td .= "Attack: {$this->_state["ship"]->getBaseAttack()} (+{$this->_state["ship"]->getAttackModifier()})<br/>";
				$td .= "Handling: {$this->_state["ship"]->getHandlingFactor()}/{$this->_state["ship"]->getHandling()}<br/>";
			}
			else {
				$td .= "<br/>";
				$td .= "<form method=\"post\"><input type=\"submit\" name=\"game_action\" value=\"END PHASE\"/>";
				$td .= "<br/><input type=\"submit\" name=\"game_action\" value=\"SURRENDER\"/></form>";
			}
			return ($td);
		}

		// P1 = top left
		public function addP1Ship()
		{
			$ship0 = new StarLight($this, 0);
			$ship0->place($this->_grid, 1, 2);
			$this->_ships[0][] = $ship0;

			$ship0 = new StarLight($this, 0);
			$ship0->place($this->_grid, 1, 5);
			$this->_ships[0][] = $ship0;

			$ship0 = new StarShadow($this, 0);
			$ship0->place($this->_grid, 5, 10);
			$this->_ships[0][] = $ship0;

			$ship0 = new StarDreadnaught($this, 0);
			$ship0->place($this->_grid, 6, 20);
			$this->_ships[0][] = $ship0;

			$ship0 = new StarShadow($this, 0);
			$ship0->place($this->_grid, 5, 30);
			$this->_ships[0][] = $ship0;

			$ship0 = new StarLight($this, 0);
			$ship0->place($this->_grid, 1, 35);
			$this->_ships[0][] = $ship0;

			$ship0 = new StarLight($this, 0);
			$ship0->place($this->_grid, 1, 38);
			$this->_ships[0][] = $ship0;
		}

		// P2 = bottom right
		public function addP2Ship()
		{
			$dy = $this->_height - 41;

			$ship0 = new StarLight($this, 1);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), $dy + 2);
			$this->_ships[1][] = $ship0;

			$ship0 = new StarLight($this, 1);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), $dy + 5);
			$this->_ships[1][] = $ship0;

			$ship0 = new StarShadow($this, 1);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 5), $dy + 10);
			$this->_ships[1][] = $ship0;

			$ship0 = new StarDreadnaught($this, 1);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 6), $dy + 20);
			$this->_ships[1][] = $ship0;

			$ship0 = new StarShadow($this, 1);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 5), $dy + 30);
			$this->_ships[1][] = $ship0;

			$ship0 = new StarLight($this, 1);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), $dy + 35);
			$this->_ships[1][] = $ship0;

			$ship0 = new StarLight($this, 1);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), $dy + 38);
			$this->_ships[1][] = $ship0;
		}

		// P3 = top right
		public function addP3Ship()
		{
			$ship0 = new StarLight($this, 2);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), 2);
			$this->_ships[2][] = $ship0;

			$ship0 = new StarLight($this, 2);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), 5);
			$this->_ships[2][] = $ship0;

			$ship0 = new StarShadow($this, 2);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 5), 10);
			$this->_ships[2][] = $ship0;

			$ship0 = new StarDreadnaught($this, 2);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 6), 20);
			$this->_ships[2][] = $ship0;

			$ship0 = new StarShadow($this, 2);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 5), 30);
			$this->_ships[2][] = $ship0;

			$ship0 = new StarLight($this, 2);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), 35);
			$this->_ships[2][] = $ship0;

			$ship0 = new StarLight($this, 2);
			$ship0->rotateLeft();
			$ship0->rotateLeft();
			$ship0->place($this->_grid, $this->_width - ($ship0->getWidth() + 1), 38);
			$this->_ships[2][] = $ship0;
		}

		// P4 = bottom left
		public function addP4Ship()
		{
			$dy = $this->_height - 41;

			$ship0 = new StarLight($this, 3);
			$ship0->place($this->_grid, 1, $dy + 2);
			$this->_ships[3][] = $ship0;

			$ship0 = new StarLight($this, 3);
			$ship0->place($this->_grid, 1, $dy + 5);
			$this->_ships[3][] = $ship0;

			$ship0 = new StarShadow($this, 3);
			$ship0->place($this->_grid, 5, $dy + 10);
			$this->_ships[3][] = $ship0;

			$ship0 = new StarDreadnaught($this, 3);
			$ship0->place($this->_grid, 6, $dy + 20);
			$this->_ships[3][] = $ship0;

			$ship0 = new StarShadow($this, 3);
			$ship0->place($this->_grid, 5, $dy + 30);
			$this->_ships[3][] = $ship0;

			$ship0 = new StarLight($this, 3);
			$ship0->place($this->_grid, 1, $dy + 35);
			$this->_ships[3][] = $ship0;

			$ship0 = new StarLight($this, 3);
			$ship0->place($this->_grid, 1, $dy + 38);
			$this->_ships[3][] = $ship0;
		}

		public function populate(bool $useObstacles) {
			$this->addP1Ship();
			$this->addP2Ship();
			if (sizeof($this->_players) > 2)
				$this->addP3Ship();
			if (sizeof($this->_players) > 3)
				$this->addP4Ship();

			if ($useObstacles) {
				for ($i = 0; $i < $this->_height; $i++) {
					for ($j = 30; $j < $this->_width - 30; $j++) {
						if ((rand(1, 200) == 1) && $this->get($j, $i) == null)
							$this->placeObstacleCluster($j, $i);
					}
				}
			}

			$this->_isWaiting = false;
		}

		public function isAreaClear($x, $y, $w, $h)
		{
			for ($i = 0; $i < $w; $i++)
			{
				for ($j = 0; $j < $h; $j++)
				{
					if ($this->get($x + $i, $y + $j) != null)
						return false;
				}
			}
			return true;
		}

		public function placeObstacleCluster($x, $y)
		{
			$size = rand(1, 10);
			$size = min($size, $this->_height - $y);
			$size = min($size, $this->_width - $x - 30);
			$w = $size;
			$h = $size;
			if (!$this->isAreaClear($x, $y, $w, $h))
				return;

			for ($i = 0; $i < $w; $i++)
			{
				for ($j = 0; $j < $h; $j++)
				{
					$obs = new Obstacle(rand(), rand());
					if ($i == 0 && $j == 0)
						$obs->setFace($h, $w);
					$this->place($x + $i, $y + $j, $obs);
				}
			}
		}

		public function resume() {
			if (!$this->_isWaiting && $this->_state["active"]) {
				if (array_key_exists("cell_id", $_POST)) {
					$cell_id = $_POST["cell_id"];
					$cell_coords = explode('x', $cell_id);
					if (sizeof($cell_coords) == 2 && is_numeric($cell_coords[0]) && is_numeric($cell_coords[1])) {
						$x = $cell_coords[0];
						$y = $cell_coords[1];
						if ($x < $this->_width && $x >= 0 && $y < $this->_height && $y >= 0 && $this->_grid[$y][$x] != null)
							$this->_grid[$y][$x]->onPost($this->_grid);
					}

					$alive = array();
					for ($i = 0; $i < sizeof($this->_players); $i++) {
						$alive[] = 0;
						for ($j = 0; $j < sizeof($this->_ships[$i]); $j++) {
							if ($this->_ships[$i][$j]->getRemainingHP() > 0)
								$alive[$i]++;
						}
					}

					$pid = $this->_state["player"];
					while (true) {
						$pid = ($pid + 1) % sizeof($this->_players);
						if ($alive[$pid] > 0)
							break;
						if ($pid == $this->_state["player"]) {
							$this->_state["active"] = false;
							$this->_state["result"] = "DRAW";
							return;
						}
					}
					if ($pid == $this->_state["player"]) {
						$this->_state["active"] = false;
						$this->_state["result"] = "END";
						return;
					}

					if ($alive[$this->_state["player"]] == 0) {
						$this->_state["phase"] = 2;
						$_POST["game_action"] = "END PHASE";
					}
				}

				if (array_key_exists("game_action", $_POST)) {
					$alive = array();
					for ($i = 0; $i < sizeof($this->_players); $i++) {
						$alive[] = 0;
						for ($j = 0; $j < sizeof($this->_ships[$i]); $j++) {
							if ($this->_ships[$i][$j]->getRemainingHP() > 0)
								$alive[$i]++;
						}
					}

					switch ($_POST["game_action"]) {
						case "END PHASE":
							switch ($this->_state["phase"]) {
								case 0:
								case 1:
									$this->_state["phase"]++;
									break;

								case 2:
									$current_player = $this->_state["player"];
									while (true) {
										$this->_state["player"] = ($this->_state["player"] + 1) % sizeof($this->_players);
										if ($this->_state["player"] == 0)
											$this->_state["turn"]++;
										if ($alive[$this->_state["player"]] > 0)
											break;
										if ($this->_state["player"] == $current_player) {
											$this->_state["active"] = false;
											$this->_state["result"] = "DRAW";
											return;
										}
									}
									if ($this->_state["player"] == $current_player) {
										$this->_state["active"] = false;
										$this->_state["result"] = "END";
										return;
									}
									$this->_state["phase"] = 0;
									break;
							}
							break;

						case "SURRENDER":
							for ($i = 0; $i < sizeof($this->_ships[$this->_state["player"]]); $i++)
								$this->_ships[$this->_state["player"]][$i]->destroy();
							break;
					}
				}
			}
		}

		public function __construct(array $players, int $width, int $height) {
			if (sizeof($players) > 4 || $width < 80 || $height < 80)
				throw new Exception("Game::__construct() => Invalid arguments!");

			$this->_players = $players;
			$this->_ships = array(array(), array(), array(), array());
			$this->_isWaiting = true;

			$this->_width = $width;
			$this->_height = $height;
			$this->_grid = array();
			for ($i = 0; $i < $height; $i++) {
				$this->_grid[] = array();
				for ($j = 0; $j < $width; $j++)
					$this->_grid[$i][] = null;
			}

			$this->_state = array(
				"player" => 0,
				"turn" => 0,
				"phase" => 0,
				"ship" => null,
				"active" => true,
				"result" => "Game in session"
			);
		}
	}
?>
