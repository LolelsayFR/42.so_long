![So_long](https://github.com/user-attachments/assets/a7bd9a51-84bc-4a29-8ab2-5998cc174d46)

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 03:29:48 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/03 22:23:10 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//      .ber Map Creation Rules for So vs Long
//      
//      
//
//      Map Elements and Their Meanings
//      
//          W: Wall - must surround all elements.
//          :: Objective Chest Close
//          ;: Objective Chest Open Only 4 required.
//          -: Weapon Chest Open.
//          ~: Weapon Chest Closed.
//          .: Empty space.
//          E: Exit door - only one allowed.
//          F: Finish Point
//          @: Player - only one allowed.
//          $: Enemy - only one allowed.
//      
//      
//
//      Map Structure and Requirements
//      
//          Rectangular shape: 
//          	The map must be a perfect rectangle.
//
//          Enclosure: 
//          	The map must be entirely enclosed by walls or the exit 
//          	(the exit is considered a closing element).
//          
//          Room requirement: 
//          	A "room" is defined as a 3x3 square 
//          	enclosed by walls, doors, or the exit.
//
//          Door placement: 
//          	Doors must be placed in the middle of walls.
//
//          Exit placement: 
//          	The exit must be placed in line one of the file 
//          	between 2 walls and respecting the door rules.
//
//          Map traversability: 
//          	The player must be able to traverse 
//          	the entire map, collect all 4 objectives, 
//          	and reach the exit without any obstacles.
//
//          Map validation: 
//          	All maps will be subjected to a validation 
//          	function at the start of the game. 
//          	Any errors will result in an error message.
//      
//      
//
//      Room Example :
//      
//      WWWWW
//      W...W
//      W.@.D  <- Door in the middle of the wall
//      W...W
//      WWWWW
//      
//      
//
//      Basic Map Example :
//      
//      WWWWWWWWWWWWW
//      W-..W.:.W...W
//      W.@.D...W...W
//      W...W..:W...W
//      WWWWWWDWWWDWW
//      W:..W...W...W
//      W...D...E.$.W
//      W...W:..W...W
//      wwwwwwwwwwwww
//
