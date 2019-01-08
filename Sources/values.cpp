#include "Headers/values.h"

const Species   g_species[36] =
{
    {"Alligator", 0, 6},
    {"Anteater", 7, 13},
    {"Bear", 14, 27},
    {"Bird", 28, 41},
    {"Bull", 42, 47},
    {"Cat", 48, 70},
    {"Chicken", 71, 79},
    {"Cow", 80, 83},
    {"Cub", 84, 99},
    {"Deer", 100, 110},
    {"Dog", 111, 126},
    {"Duck", 127, 143},
    {"Eagle", 144, 152},
    {"Elephant", 153, 163},
    {"Frog", 164, 181},
    {"Goat", 182, 188},
    {"Gorilla", 189, 198},
    {"Hamster", 199, 207},
    {"Hippo", 208, 214},
    {"Horse", 215, 230},
    {"Koala", 231, 239},
    {"Kangaroo", 240, 247},
    {"Lion", 248, 254},
    {"Monkey", 255, 262},
    {"Mouse", 263, 277},
    {"Octopus", 278, 281},
    {"Ostrich", 282, 291},
    {"Penguin", 292, 304},
    {"Pig", 305, 320},
    {"Rabbit", 321, 341},
    {"Rhino", 342, 347},
    {"Sheep", 348, 360},
    {"Squirrel", 361, 380},
    {"Tiger", 381, 387},
    {"Wolf", 388, 398},
    {"Special Characters", 399, 429}
};

const Villagers   g_villagers[430] =
{
    {"Alfonso", 0x005d}, // Alligator
    {"Alli", 0x005e}, // Alligator
    {"Boots", 0x005f}, // Alligator
    {"Del", 0x0060}, // Alligator
    {"Drago", 0x0063}, // Alligator
    {"Gayle", 0x0062}, // Alligator
    {"Sly", 0x0061}, // Alligator
    {"Anabelle", 0x0003}, // Anteater
    {"Annalisa", 0x0005}, // Anteater
    {"Antonio", 0x0001}, // Anteater
    {"Cyrano", 0x0000}, // Anteater
    {"Olaf", 0x0006}, // Anteater
    {"Pango", 0x0002}, // Anteater
    {"Snooty", 0x0004}, // Anteater
    {"Beardo", 0x0013}, // Bear
    {"Charlise", 0x0012}, // Bear
    {"Chow", 0x000a}, // Bear
    {"Curt", 0x0009}, // Bear
    {"Grizzly", 0x000f}, // Bear
    {"Groucho", 0x000c}, // Bear
    {"Ike", 0x0011}, // Bear
    {"Klaus", 0x0014}, // Bear
    {"Nate", 0x000b}, // Bear
    {"Paula", 0x0010}, // Bear
    {"Pinky", 0x0008}, // Bear
    {"Teddy", 0x0007}, // Bear
    {"Tutu", 0x000d}, // Bear
    {"Ursala", 0x000e}, // Bear
    {"Admiral", 0x001b}, // Bird
    {"Anchovy", 0x0017}, // Bird
    {"Jacques", 0x001f}, // Bird
    {"Jakey/Jacob", 0x001d}, // Bird
    {"Jay", 0x0015}, // Bird
    {"Jitters", 0x0019}, // Bird
    {"Lucha", 0x001e}, // Bird
    {"Medli", 0x0022}, // Bird
    {"Midge", 0x001c}, // Bird
    {"Peck", 0x0020}, // Bird
    {"Piper", 0x001a}, // Bird
    {"Robin", 0x0016}, // Bird
    {"Sparro", 0x0021}, // Bird
    {"Twiggy", 0x0018}, // Bird
    {"Angus", 0x0023}, // Bull
    {"Coach", 0x0027}, // Bull
    {"Rodeo", 0x0024}, // Bull
    {"Stu", 0x0025}, // Bull
    {"T-Bone", 0x0026}, // Bull
    {"Vic", 0x0028}, // Bull
    {"Ankha", 0x003c}, // Cat
    {"Bob", 0x0029}, // Cat
    {"Felicity", 0x003a}, // Cat
    {"Felyne", 0x003f}, // Cat
    {"Kabuki", 0x0032}, // Cat
    {"Katt", 0x003e}, // Cat
    {"Kid Cat", 0x0033}, // Cat
    {"Kiki", 0x002d}, // Cat
    {"Kitty", 0x0037}, // Cat
    {"Lolly", 0x003b}, // Cat
    {"Merry", 0x0039}, // Cat
    {"Mitzi", 0x002a}, // Cat
    {"Moe", 0x0031}, // Cat
    {"Monique", 0x0034}, // Cat
    {"Olivia", 0x002c}, // Cat
    {"Punchy", 0x002f}, // Cat
    {"Purrl", 0x0030}, // Cat
    {"Rosie", 0x002b}, // Cat
    {"Rudy", 0x003d}, // Cat
    {"Stinky", 0x0036}, // Cat
    {"Tabby", 0x0035}, // Cat
    {"Tangy", 0x002e}, // Cat
    {"Tom", 0x0038}, // Cat
    {"Ava", 0x0053}, // Chicken
    {"Becky", 0x0054}, // Chicken
    {"Benedict", 0x0051}, // Chicken
    {"Broffina", 0x0057}, // Chicken
    {"Egbert", 0x0052}, // Chicken
    {"Goose", 0x0050}, // Chicken
    {"Ken", 0x0058}, // Chicken
    {"Knox", 0x0056}, // Chicken
    {"Plucky", 0x0055}, // Chicken
    {"Naomi", 0x005c}, // Cow
    {"Norma", 0x005b}, // Cow
    {"Patty", 0x0059}, // Cow
    {"Tipper", 0x005a}, // Cow
    {"Barold", 0x004d}, // Cub
    {"Bluebear", 0x0040}, // Cub
    {"Cheri", 0x0049}, // Cub
    {"Chester", 0x004c}, // Cub
    {"June", 0x004a}, // Cub
    {"Kody", 0x0044}, // Cub
    {"Maple", 0x0041}, // Cub
    {"Marty", 0x004f}, // Cub
    {"Murphy", 0x0047}, // Cub
    {"Olive", 0x0048}, // Cub
    {"Pekoe", 0x004b}, // Cub
    {"Poncho", 0x0042}, // Cub
    {"Pudge", 0x0043}, // Cub
    {"Stitches", 0x0045}, // Cub
    {"Tammy", 0x004e}, // Cub
    {"Vladimir", 0x0046}, // Cub
    {"Bam", 0x0065}, // Deer
    {"Beau", 0x006b}, // Deer
    {"Bruce", 0x0067}, // Deer
    {"Chelsea", 0x006e}, // Deer
    {"Deirdre", 0x0068}, // Deer
    {"Diana", 0x006c}, // Deer
    {"Erik", 0x006d}, // Deer
    {"Fauna", 0x0064}, // Deer
    {"Fuchsia", 0x006a}, // Deer
    {"Lopez", 0x0069}, // Deer
    {"Zell", 0x0066}, // Deer
    {"Bea", 0x0079}, // Dog
    {"Benjamin", 0x007c}, // Dog
    {"Biskit", 0x0072}, // Dog
    {"Bones", 0x0073}, // Dog
    {"Butch", 0x0070}, // Dog
    {"Cherry", 0x007d}, // Dog
    {"Cookie", 0x0077}, // Dog
    {"Daisy", 0x0076}, // Dog
    {"Goldie", 0x006f}, // Dog
    {"Lucky", 0x0071}, // Dog
    {"Mac", 0x007a}, // Dog
    {"Maddie", 0x0078}, // Dog
    {"Marcel", 0x007b}, // Dog
    {"Portia", 0x0074}, // Dog
    {"Shep", 0x007e}, // Dog
    {"Walker", 0x0075}, // Dog
    {"Bill", 0x007f}, // Duck
    {"Deena", 0x0083}, // Duck
    {"Derwin", 0x0087}, // Duck
    {"Drake", 0x0088}, // Duck
    {"Freckles", 0x0086}, // Duck
    {"Gloria", 0x008d}, // Duck
    {"Joey", 0x0080}, // Duck
    {"Ketchup", 0x008c}, // Duck
    {"Maelle", 0x0082}, // Duck
    {"Mallary", 0x0085}, // Duck
    {"Miranda", 0x008b}, // Duck
    {"Molly", 0x008e}, // Duck
    {"Pate", 0x0081}, // Duck
    {"Pompom", 0x0084}, // Duck
    {"Quillson", 0x008f}, // Duck
    {"Scoot", 0x0089}, // Duck
    {"Weber", 0x008a}, // Duck
    {"Amelia", 0x011c}, // Eagle
    {"Apollo", 0x011b}, // Eagle
    {"Avery", 0x011f}, // Eagle
    {"Buzz", 0x011e}, // Eagle
    {"Celia", 0x0123}, // Eagle
    {"Frank", 0x0120}, // Eagle
    {"Keaton", 0x0122}, // Eagle
    {"Pierce", 0x011d}, // Eagle
    {"Sterling", 0x0121}, // Eagle
    {"Axel", 0x0096}, // Elephant
    {"Big Top", 0x0092}, // Elephant
    {"Chai", 0x009a}, // Elephant
    {"Dizzy", 0x0091}, // Elephant
    {"Ellie", 0x0097}, // Elephant
    {"Eloise", 0x0093}, // Elephant
    {"Margie", 0x0094}, // Elephant
    {"Opal", 0x0090}, // Elephant
    {"Paolo", 0x0095}, // Elephant
    {"Tia", 0x0099}, // Elephant
    {"Tucker", 0x0098}, // Elephant
    {"Camofrog", 0x009e}, // Frog
    {"Cousteau", 0x00a4}, // Frog
    {"Croque", 0x00aa}, // Frog
    {"Diva", 0x00ab}, // Frog
    {"Drift", 0x009f}, // Frog
    {"Frobert", 0x009d}, // Frog
    {"Gigi", 0x00a9}, // Frog
    {"Henry", 0x00ac}, // Frog
    {"Huck", 0x00a5}, // Frog
    {"Jambette", 0x00a7}, // Frog
    {"Jeremiah", 0x00a2}, // Frog
    {"Lily", 0x009b}, // Frog
    {"Prince", 0x00a6}, // Frog
    {"Puddles", 0x00a1}, // Frog
    {"Raddle", 0x00a8}, // Frog
    {"Ribbot", 0x009c}, // Frog
    {"Tad", 0x00a3}, // Frog
    {"Wart Jr.", 0x00a0}, // Frog
    {"Billy", 0x00af}, // Goat
    {"Chevre", 0x00ad}, // Goat
    {"Gruff", 0x00b0}, // Goat
    {"Kidd", 0x00b2}, // Goat
    {"Nan", 0x00ae}, // Goat
    {"Pashmina", 0x00b3}, // Goat
    {"Velma", 0x00b1}, // Goat
    {"Al", 0x00ba}, // Gorilla
    {"Boone", 0x00b6}, // Gorilla
    {"Boyd", 0x00b8}, // Gorilla
    {"Cesar", 0x00b4}, // Gorilla
    {"Hans", 0x00bc}, // Gorilla
    {"Louie", 0x00b7}, // Gorilla
    {"Peewee", 0x00b5}, // Gorilla
    {"Rilla", 0x00bd}, // Gorilla
    {"Rocket", 0x00bb}, // Gorilla
    {"Violet", 0x00b9}, // Gorilla
    {"Apple", 0x00bf}, // Hamster
    {"Clay", 0x00c3}, // Hamster
    {"Flurry", 0x00c4}, // Hamster
    {"Graham", 0x00c0}, // Hamster
    {"Hamlet", 0x00be}, // Hamster
    {"Hamphrey", 0x00c5}, // Hamster
    {"Holden", 0x00c6}, // Hamster
    {"Rodney", 0x00c1}, // Hamster
    {"Soleil", 0x00c2}, // Hamster
    {"Bertha", 0x00c9}, // Hippo
    {"Biff", 0x00ca}, // Hippo
    {"Bitty", 0x00cb}, // Hippo
    {"Bubbles", 0x00c8}, // Hippo
    {"Harry", 0x00cc}, // Hippo
    {"Hippeux", 0x00cd}, // Hippo
    {"Rocco", 0x00c7}, // Hippo
    {"Annalise", 0x00d7}, // Horse
    {"Buck", 0x00ce}, // Horse
    {"Cleo", 0x00d5}, // Horse
    {"Clyde", 0x00d8}, // Horse
    {"Colton", 0x00d9}, // Horse
    {"Ed", 0x00d4}, // Horse
    {"Elmer", 0x00d1}, // Horse
    {"Epona", 0x00dd}, // Horse
    {"Filly", 0x00dc}, // Horse
    {"Julian", 0x00db}, // Horse
    {"Papi", 0x00da}, // Horse
    {"Peaches", 0x00d6}, // Horse
    {"Roscoe", 0x00d2}, // Horse
    {"Savannah", 0x00d0}, // Horse
    {"Victoria", 0x00cf}, // Horse
    {"Winnie", 0x00d3}, // Horse
    {"Alice", 0x00df}, // Koala
    {"Canberra", 0x00e4}, // Koala
    {"Eugene", 0x00e6}, // Koala
    {"Gonzo", 0x00e2}, // Koala
    {"Lyman", 0x00e5}, // Koala
    {"Melba", 0x00e0}, // Koala
    {"Ozzie", 0x00e3}, // Koala
    {"Sydney", 0x00e1}, // Koala
    {"Yuka", 0x00de}, // Koala
    {"Astrid", 0x00ea}, // Kangaroo
    {"Carrie", 0x00e9}, // Kangaroo
    {"Kitt", 0x00e7}, // Kangaroo
    {"Marcie", 0x00ee}, // Kangaroo
    {"Mathilda", 0x00e8}, // Kangaroo
    {"Rooney", 0x00ed}, // Kangaroo
    {"Sylvia", 0x00eb}, // Kangaroo
    {"Walt", 0x00ec}, // Kangaroo
    {"Bud", 0x00ef}, // Lion
    {"Elvis", 0x00f0}, // Lion
    {"Leopold", 0x00f2}, // Lion
    {"Lionel", 0x00f5}, // Lion
    {"Mott", 0x00f3}, // Lion
    {"Rex", 0x00f1}, // Lion
    {"Rory", 0x00f4}, // Lion
    {"Deli", 0x00fd}, // Monkey
    {"Elise", 0x00fa}, // Monkey
    {"Flip", 0x00fb}, // Monkey
    {"Monty", 0x00f9}, // Monkey
    {"Nana", 0x00f6}, // Monkey
    {"Shari", 0x00fc}, // Monkey
    {"Simon", 0x00f7}, // Monkey
    {"Tammi", 0x00f8}, // Monkey
    {"Anicotti", 0x0106}, // Mouse
    {"Bella", 0x0100}, // Mouse
    {"Bettina", 0x0109}, // Mouse
    {"Bree", 0x0101}, // Mouse
    {"Broccolo", 0x0107}, // Mouse
    {"Candi", 0x0104}, // Mouse
    {"Chadder", 0x010c}, // Mouse
    {"Dora", 0x00fe}, // Mouse
    {"Greta", 0x010a}, // Mouse
    {"Limberg", 0x00ff}, // Mouse
    {"Moose", 0x0108}, // Mouse
    {"Penelope", 0x010b}, // Mouse
    {"Rizzo", 0x0105}, // Mouse
    {"Rod", 0x0103}, // Mouse
    {"Samson", 0x0102}, // Mouse
    {"Inkwell", 0x0110}, // Octopus
    {"Marina", 0x010e}, // Octopus
    {"Octavian", 0x010d}, // Octopus
    {"Zucker", 0x010f}, // Octopus
    {"Blanche", 0x0118}, // Ostrich
    {"Cranston", 0x0116}, // Ostrich
    {"Flora", 0x0119}, // Ostrich
    {"Gladys", 0x0112}, // Ostrich
    {"Julia", 0x0115}, // Ostrich
    {"Phil", 0x0117}, // Ostrich
    {"Phoebe", 0x011a}, // Ostrich
    {"Queenie", 0x0111}, // Ostrich
    {"Sandy", 0x0113}, // Ostrich
    {"Sprocket", 0x0114}, // Ostrich
    {"Aurora", 0x0124}, // Penguin
    {"Boomer", 0x012c}, // Penguin
    {"Cube", 0x0126}, // Penguin
    {"Flo", 0x012f}, // Penguin
    {"Friga", 0x0128}, // Penguin
    {"Gwen", 0x0129}, // Penguin
    {"Hopper", 0x0127}, // Penguin
    {"Iggly", 0x012d}, // Penguin
    {"Puck", 0x012a}, // Penguin
    {"Roald", 0x0125}, // Penguin
    {"Sprinkle", 0x0130}, // Penguin
    {"Tex", 0x012e}, // Penguin
    {"Wade", 0x012b}, // Penguin
    {"Agnes", 0x013f}, // Pig
    {"Boris", 0x0138}, // Pig
    {"Chops", 0x013c}, // Pig
    {"Cobb", 0x0137}, // Pig
    {"Curly", 0x0131}, // Pig
    {"Crackle/Spork", 0x0136}, // Pig
    {"Gala", 0x013b}, // Pig
    {"Ganon", 0x0140}, // Pig
    {"Hugh", 0x0134}, // Pig
    {"Kevin", 0x013d}, // Pig
    {"Lucy", 0x0135}, // Pig
    {"Maggie", 0x0139}, // Pig
    {"Pancetti", 0x013e}, // Pig
    {"Peggy", 0x013a}, // Pig
    {"Rasher", 0x0133}, // Pig
    {"Truffles", 0x0132}, // Pig
    {"Bonbon", 0x0152}, // Rabbit
    {"Bunnie", 0x0141}, // Rabbit
    {"Carmen", 0x0151}, // Rabbit
    {"Chrissy", 0x014e}, // Rabbit
    {"Claude", 0x014c}, // Rabbit
    {"Coco", 0x0143}, // Rabbit
    {"Cole", 0x0153}, // Rabbit
    {"Doc", 0x014b}, // Rabbit
    {"Dotty", 0x0142}, // Rabbit
    {"Francine", 0x014d}, // Rabbit
    {"Gabi", 0x0146}, // Rabbit
    {"Gaston", 0x0145}, // Rabbit
    {"Genji", 0x0149}, // Rabbit
    {"Hopkins", 0x014f}, // Rabbit
    {"Mira", 0x0154}, // Rabbit
    {"O'Hare", 0x0150}, // Rabbit
    {"Pippy", 0x0147}, // Rabbit
    {"Ruby", 0x014a}, // Rabbit
    {"Snake", 0x0144}, // Rabbit
    {"Tiffany", 0x0148}, // Rabbit
    {"Toby", 0x0155}, // Rabbit
    {"Hornsby", 0x0159}, // Rhino
    {"Merengue", 0x015a}, // Rhino
    {"Rene", 0x015b}, // Rhino
    {"Rhonda", 0x0157}, // Rhino
    {"Spike", 0x0158}, // Rhino
    {"Tank", 0x0156}, // Rhino
    {"Baabara", 0x015d}, // Sheep
    {"Cashmere", 0x0160}, // Sheep
    {"Curlos", 0x0162}, // Sheep
    {"toile", 0x0168}, // Sheep
    {"Eunice", 0x015e}, // Sheep
    {"Frita", 0x0165}, // Sheep
    {"Muffy", 0x0166}, // Sheep
    {"Pietro", 0x0167}, // Sheep
    {"Stella", 0x015f}, // Sheep
    {"Timbra", 0x0164}, // Sheep
    {"Vesta", 0x015c}, // Sheep
    {"Wendy", 0x0163}, // Sheep
    {"Willow", 0x0161}, // Sheep
    {"Agent S", 0x016e}, // Squirrel
    {"Blaire", 0x016a}, // Squirrel
    {"Cally", 0x0174}, // Squirrel
    {"Caroline", 0x016f}, // Squirrel
    {"Cece", 0x017b}, // Squirrel
    {"Filbert", 0x016b}, // Squirrel
    {"Hazel", 0x017a}, // Squirrel
    {"Marshal", 0x0179}, // Squirrel
    {"Mint", 0x0172}, // Squirrel
    {"Nibbles", 0x016d}, // Squirrel
    {"Peanut", 0x0169}, // Squirrel
    {"Pecan", 0x016c}, // Squirrel
    {"Poppy", 0x0177}, // Squirrel
    {"Ricky", 0x0173}, // Squirrel
    {"Sally", 0x0170}, // Squirrel
    {"Sheldon", 0x0178}, // Squirrel
    {"Static", 0x0171}, // Squirrel
    {"Sylvana", 0x0176}, // Squirrel
    {"Tasha", 0x0175}, // Squirrel
    {"Vich", 0x017c}, // Squirrel
    {"Bangle", 0x0180}, // Tiger
    {"Bianca", 0x0183}, // Tiger
    {"Claudia", 0x0182}, // Tiger
    {"Leonardo", 0x0181}, // Tiger
    {"Rolf", 0x017d}, // Tiger
    {"Rowan", 0x017e}, // Tiger
    {"Tybalt", 0x017f}, // Tiger
    {"Chief", 0x0184}, // Wolf
    {"Dobie", 0x0188}, // Wolf
    {"Fang", 0x018a}, // Wolf
    {"Freya", 0x0189}, // Wolf
    {"Kyle", 0x018d}, // Wolf
    {"Lobo", 0x0185}, // Wolf
    {"Skye", 0x018c}, // Wolf
    {"Vivian", 0x018b}, // Wolf
    {"Whitney", 0x0187}, // Wolf
    {"Wolfgang", 0x0186}, // Wolf
    {"W. Link", 0x018e}, // Wolf

    {"Villager", 0x200F}, // Special
    {"Isabelle", 0x2000}, // Special
    {"K. K. Slider", 0x2007}, // Special
    {"Tom Nook", 0x2004}, // Special
    {"Timmy&Tommy", 0x200D}, // Special
    {"Mable", 0x2006}, // Special
    {"Reese", 0x2002}, // Special
    {"Cyrus", 0x2003}, // Special
    {"Digby", 0x2001}, // Special
    {"Rover", 0x200C}, // Special
    {"Resetti", 0x2009}, // Special
    {"Blathers", 0x200B}, // Special
    {"Celeste", 0x200A}, // Special
    {"Kicks", 0x2008}, // Special
    {"Kapp'n", 0x200E}, // Special
    {"Nat", 0x1008}, // Special
    {"Chip", 0x1007}, // Special
    {"Copper", 0x1000}, // Special
    {"Booker", 0x1001}, // Special
    {"Gulliver", 0x100D}, // Special
    {"Joan", 0x100A}, // Special
    {"Pascal", 0x100C}, // Special
    {"Sahara", 0x100E}, // Special
    {"Wendell", 0x100B}, // Special
    {"Pave", 0x1006}, // Special
    {"Zipper", 0x1004}, // Special
    {"Jack", 0x1003}, // Special
    {"Franklin", 0x1009}, // Special
    {"Jingle", 0x1002}, // Special
    {"Blanca", 0x1005}, // Special
    {"Lottie", 0x2005} // Special
};
