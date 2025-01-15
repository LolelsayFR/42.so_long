![So_long](https://github.com/user-attachments/assets/a7bd9a51-84bc-4a29-8ab2-5998cc174d46)

.ber Map Creation Rules for So vs Long

Map Elements and Their Meanings

    W: Wall - must surround all elements.
    :: Objective Chest Close
    ;: Objective Chest Open Only 4 required.
    -: Weapon Chest Open.
    ~: Weapon Chest Closed.
    .: Empty space.
    E: Exit door - only one allowed.
    F: Finish Point
    @: Player - only one allowed.
    $: Enemy - A ghost.
    &: Enemy - Spike

More info

    Exit door can be opened only if you have all objectives item colected.
    The ghosts can noclip and chase the player througth the walls.

Map Structure and Requirements

    Rectangular shape: 
    	The map must be a perfect rectangle.

    Enclosure: 
    	The map must be entirely enclosed by walls or the exit 
    	(the exit is considered a closing element).

    Room requirement (optional but good): 
    	A "room" is defined as a 5x5 square 
    	enclosed by walls or doors;

    Door placement (optional): 
    	Doors must be placed in the middle of walls.

    Map traversability: 
    	The player must be able to traverse 
    	the entire map, collect all 4 objectives, 
    	and reach the finish point without any obstacles.

    Map validation: 
    	All maps will be subjected to a validation 
    	function at the start of the game. 
    	Any errors will result in an error message.



Basic Map Example :

WWWWWWWWWWWWW
W-..W.:.W...W
W.@.D...W...W
W...W..:W...W
WWWWWWDWWWDWW
W:..W...W...W
W...D...E.D.W
W...W:..W...W
WWWWWWWWWWWWW

