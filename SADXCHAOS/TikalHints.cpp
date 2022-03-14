#include "TikalHints.h"
#include "pch.h"
//"The frog you are looking for Test 123456 is up ahead Testing How 123456789abcde", //max char for entire text box without new line can be 79 characters 
//	"The frog you are looking for Test 123456\nis up ahead Testing How123456789abcdefg", //max char for each line with new line can be up to 81 characters (counting the new line)
//A hint with \n can be 81 character (\n counts as 2)
//A hint with no new line can be 79 charaters
void RandomTikalHint()
{
	int hintrand = rand() % HintSize;
	LoadAutoHint(Hints[hintrand], Voices[hintrand]);
	strcpy_s(LastEffect, 128, "Tikal Hint");
}
const HintText_Text const Hints[67][3] = {
{
{ "Watch out for the cars!.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Aim for Chaos' head when he's off guard.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "You can punch the small\nbubbles of water.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Jump on panel number one. It will take\nyou to panels two and three. Jump as", 260 }, // text, time
{ "soon as you land on a panel\nor else you'll fall.", 120 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Insert the plug in the\nopening next to the door.", 130 }, // text, time
{ "You need to grab hold of\nthe end of the plug.", 140 }, //Second page
{ 0 } //idk 3rd page or always null?
},//if you read this
  //you mom gay
{
{ "If you're hanging from a cord,\nuse the directional pad to sway.", 180 }, // text, time
{ "By touching the cord next to you,\nyou will be able to switch cords.", 180 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "To pull out a plug, hold it and shake it.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Even if you're frozen, jump a couple of\ntimes.", 160 }, // text, time
{ "and you should be able to crack through.",140 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Try and find places\nwhere it's not windy.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Get a load of this!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "You can break through the wall if you use dynamite.", 180 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "OOF", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "You're the... Chao!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Father; please don't!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "My true hope is that someday\nwe'll understand each other.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "(gasps)", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Father!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "(groans)", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Keep your balance;\nor else you'll fall off.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Hide in here.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Be careful of Leon.\nHe appears suddenly.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "You're going the wrong way.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Be brave; blue hedgehog.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Watch out for the helicopter propellers.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Save the animals.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Use the dash panels.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "This way!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Sega!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "I won't obey!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Wow...", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "I'm shocked...!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Oh please!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "I'm Tikal.\nAnd you are?", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "But the number seven...", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Why?", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Select a memory card.", 100 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Oh no!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Oh no!", 69 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "The ice looks kinda tasty!", 130 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "What a huge house!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Froggy; where are you?", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Maybe I'll go home.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Uh; exits? Exits?", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "I wanna go fishing!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "So; that's his core.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Did you know that there are\n15 animals hidden in this stage?", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Hey you. You're finally awake. You were\ntrying to cross the border right?", 380 }, // text, time
{ "Walked right into that Imperial ambush\nsame as us, and that Thief over there.", 380 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "I Used To Be An Adventurer Like You\nThen I Took An Arrow In The Knee.", 260 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Hello there friend!\nHow are you?", 140 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Attacking other countries;\nstealing; and killing...", 240 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "My father is coming here soon.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "They came...\nand my Father...", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "No; don't go any closer!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "No way!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "I won't obey!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "You must save Amy.\nHurry to the Mystic Ruins!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Go to the Captain's Room.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "The water has been contaminated.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Aim for the frog\nand cast your lure!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "The tentacle turns\nred when you hit it.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Umm.. Which memory card?", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Umm.. Which File?", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Umm... Which character?", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "You don't have enough memory in the memory card.", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "I got it!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "What a big lake!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
{
{ "Wow; it's dark in here!", 120 }, // text, time
{ 0 }, //Second page
{ 0 } //idk 3rd page or always null?
},
};
size_t HintSize = LengthOfArray(Hints);
int Voices[] = {
1857,
181,
182,
1550,
1595,
1596,
1597,
1606,
2043,
174, //Get a load of this!
1955,
55555, //Custom OOF Voice
919,
1024,
1222,
1356,
1444,
1465,
1594,
1665,
1674,
1677,
1714,
1861,
1875,
1941,
1954,
2010,
1440,
1352,
1141,
1103,
746,
742,
89,
18,
164,//knux oh-no
165,//sonic oh-no
241,
298,
310,
319,
344,
367,
389,//core
145469,//Omochao
69420, //skyrim intro
42069, //skyrim adventure arrow
733,
1028,
1100,
1139,
1213,
1437,
1440,
1562,
1692,
1939,
1962,
1970,
126,//what mem card - big
127,//Which file - big
130,//what character - big
143,//not enough mem - big
214,//I got it - sonic
230,//what a big lake! - big
287//its so dark in here - big
};