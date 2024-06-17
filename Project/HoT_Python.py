import random
from enum import Enum
import sys


# enum declarations
class Character(Enum):
    WARRIOR = 1
    MAGE = 2
    ARCHER = 3


# Enemy class, which is used to give each enemy health and damage
class Enemy:
    def __init__(self, dmg, hp, maxHp):
        self.enemyDmg = dmg
        self.enemyHp = hp
        self.maxHealth = maxHp

    def setEnemyDmg(self, d):
        self.enemyDmg = d

    def getEnemyDmg(self):
        return self.enemyDmg

    def setEnemyHp(self, h):
        self.enemyHp = h

    def getEnemyHp(self):
        return self.enemyHp

    def setEnemyMaxHp(self, mH):
        self.maxHealth = mH

    def getEnemyMaxHp(self):
        return self.maxHealth


def enemyAttack(playerHp, enemyDmg, enemy):
    playerHp -= enemyDmg
    print("The", enemy, "dealt", enemyDmg, "damage to you")


def playerAttack(enemyHp, playerDmg, enemyDmg, playerHp, enemy):
    enemyHp -= playerDmg
    print("You dealt", playerDmg, "damage")

    if enemyHp > 0:
        enemyAttack(playerHp, enemyDmg, enemy)


def checkDeathFunc(playerHp, enemy, turn, hpPotions):
    print()

    if playerHp <= 0:
        print("YOU DIED!")
        print("GAME OVER")
        print(
            "-----------------------------------------------------------------------------------------------------------"
        )
    else:
        print("You killed the", enemy, "in", turn, "turn(s)!")
        print("You have", playerHp, "Hp left.")
        print("You gained 1 health potion.")

        hpPotions += 1
        turn = 0


def attackFunc(
    enemy,
    playerHp,
    enemyHp,
    maxHp,
    enemyMaxHp,
    cmd,
    turn,
    playerDmg,
    hpPotions,
    healAmount,
    enemyDmg,
):
    print("You engage the", enemy, "!")

    while playerHp > 0 and enemyHp > 0:
        print("You have ({}/{}) health left".format(playerHp, maxHp))
        print("The", enemy, "has ({}/{}) health left".format(enemyHp, enemyMaxHp))
        print("You have", hpPotions, "health potions left\n")

        cmd = input("What will you do? (a: attack, h: heal) ")

        # input validation
        while cmd != "a" and cmd != "h":
            cmd = input("Please enter a valid command: (a: attack, h: heal) ")

        # runs if the user decides to attack
        if cmd == "a":
            playerAttack(enemyHp, playerDmg, enemyDmg, playerHp, enemy)
            turn += 1
        # this allows the user to heal on their turn instead of attacking
        elif hpPotions > 0:
            # if the user's health is at the max health, this forces them to attack
            if playerHp == maxHp:
                print("You are already at full health. You must attack!")
                playerAttack(enemyHp, playerDmg, enemyDmg, playerHp, enemy)
            # allows the user to heal if they are not at max health
            else:
                playerHp += healAmount
                print("You drink a health potion")
                hpPotions -= 1
                # makes sure the user does not have more health than their max health
                if playerHp >= maxHp:
                    playerHp = maxHp

                # allows the enemy to attack after the player heals
                if enemyHp > 0:
                    enemyAttack(playerHp, enemyDmg, enemy)
                # counts how many turns it takes to kill the enemy
                turn += 1
        # forces the user to attack if they have no health potions
        else:
            print("You are out of health potions and must attack")
            playerAttack(enemyHp, playerDmg, enemyDmg, playerHp, enemy)
            turn += 1

    # checks to see if the user died or not
    checkDeathFunc(playerHp, enemy, turn, hpPotions)


def runFunc(
    randNum,
    enemy,
    playerHp,
    enemyHp,
    maxHp,
    enemyMaxHp,
    cmd,
    turn,
    playerDmg,
    hpPotions,
    healAmount,
    enemyDmg,
):
    # generates a new random number every time the program is run
    random.seed()
    # generates a random number between 0 and 1
    randNum = random.randint(0, 1)
    # the user has a 50% chance to escape successfully
    if randNum == 0:
        print("You escaped successfully!")
    # forces the user to attack if they failed to run
    else:
        print("You failed to escape the", enemy, ". You must attack!")
        attackFunc(
            enemy,
            playerHp,
            enemyHp,
            maxHp,
            enemyMaxHp,
            cmd,
            turn,
            playerDmg,
            hpPotions,
            healAmount,
            enemyDmg,
        )


def cantHeal(
    randNum,
    enemy,
    playerHp,
    enemyHp,
    maxHp,
    enemyMaxHp,
    cmd,
    turn,
    playerDmg,
    hpPotions,
    healAmount,
    enemyDmg,
):
    # input validation
    while cmd != "a" and cmd != "r":
        cmd = input("Enter a valid command: (a: attack, r: run) ")
    # allows the user to run only if canRun is true (used in the bossFunc)
    if cmd == "r":
        runFunc(
            randNum,
            enemy,
            playerHp,
            enemyHp,
            maxHp,
            enemyMaxHp,
            cmd,
            turn,
            playerDmg,
            hpPotions,
            healAmount,
            enemyDmg,
        )
    # runs the attackFunc
    else:
        attackFunc(
            enemy,
            playerHp,
            enemyHp,
            maxHp,
            enemyMaxHp,
            cmd,
            turn,
            playerDmg,
            hpPotions,
            healAmount,
            enemyDmg,
        )


def choiceFunc(
    cmd,
    randNum,
    enemy,
    healAmount,
    playerHp,
    hpPotions,
    potionsDrank,
    maxHp,
    enemyHp,
    enemyDmg,
    playerDmg,
    turn,
    enemyMaxHp,
):
    # input validation
    while cmd != "a" and cmd != "r" and cmd != "h":
        cmd = input("Please enter a valid command: (a: attack, r: run, h: heal) ")
        if cmd == "h":
            # forces the user to choose another option if they are at max health
            if playerHp == maxHp:
                cmd = input(
                    "You are already at full health. Enter a valid command (a: attack, r: run) "
                )
                cantHeal(
                    randNum,
                    enemy,
                    playerHp,
                    enemyHp,
                    maxHp,
                    enemyMaxHp,
                    cmd,
                    turn,
                    playerDmg,
                    hpPotions,
                    healAmount,
                    enemyDmg,
                )
            # runs if the user is not at max health and has at least 1 health potion
            elif hpPotions > 0:
                # the user can drink more than one potion if they want
                potionsDrank = int(
                    input("How many health potions do you want to drink? ")
                )
                # input validation
                while hpPotions < potionsDrank or potionsDrank <= 0:
                    print(
                        "You have",
                        hpPotions,
                        "health potion(s) left. You must drink at least 1 potion.",
                    )
                    potionsDrank = int(
                        input(
                            "Please enter a valid number of health potions to drink: "
                        )
                    )

                print()
                # for loop that adds the health to the user and removes the health potions from their inventory
                for _ in range(potionsDrank):
                    if playerHp >= maxHp:
                        print(
                            "You are at full health and can't drink",
                            potionsDrank,
                            "health potions",
                        )
                        break
                    playerHp += healAmount
                    hpPotions -= 1

                # makes sure the user does not have more health than their max health
                if playerHp >= maxHp:
                    playerHp = maxHp

                print("Your health is now", playerHp)
                print("You have", hpPotions, "health potion(s) left.\n")

                cmd = input("Now what will you do? (a: attack, r: run) ")
                cantHeal(
                    randNum,
                    enemy,
                    playerHp,
                    enemyHp,
                    maxHp,
                    enemyMaxHp,
                    cmd,
                    turn,
                    playerDmg,
                    hpPotions,
                    healAmount,
                    enemyDmg,
                )
            # runs if the user wants to heal, but can't because they have no health potions
            else:
                cmd = input(
                    "You can't heal because you have no potions. Enter a valid command: (a: attack, r: run) "
                )
                cantHeal(
                    randNum,
                    enemy,
                    playerHp,
                    enemyHp,
                    maxHp,
                    enemyMaxHp,
                    cmd,
                    turn,
                    playerDmg,
                    hpPotions,
                    healAmount,
                    enemyDmg,
                )
        # runs if the user chose to run
        elif cmd == "r":
            runFunc(
                randNum,
                enemy,
                playerHp,
                enemyHp,
                maxHp,
                enemyMaxHp,
                cmd,
                turn,
                playerDmg,
                hpPotions,
                healAmount,
                enemyDmg,
            )
        # runs if the user chose to attack
        else:
            attackFunc(
                enemy,
                playerHp,
                enemyHp,
                maxHp,
                enemyMaxHp,
                cmd,
                turn,
                playerDmg,
                hpPotions,
                healAmount,
                enemyDmg,
            )


def bossFunc(
    cmd,
    enemy,
    healAmount,
    playerHp,
    hpPotions,
    potionsDrank,
    maxHp,
    enemyHp,
    enemyDmg,
    playerDmg,
    turn,
    enemyMaxHp,
):
    # input validation
    while cmd != "a" and cmd != "h":
        cmd = input("Please enter a valid command: (a: attack, h: heal) ")

    # runs if the user chose to heal
    if cmd == "h":
        # forces the user to choose another option if they are at max health
        if playerHp == maxHp:
            print("You are already at full health. You must attack!")
            attackFunc(
                enemy,
                playerHp,
                enemyHp,
                maxHp,
                enemyMaxHp,
                cmd,
                turn,
                playerDmg,
                hpPotions,
                healAmount,
                enemyDmg,
            )
        # the user can drink more than one potion if they want
        elif hpPotions > 0:
            potionsDrank = int(input("How many health potions do you want to drink? "))
            # input validation
            while hpPotions < potionsDrank or potionsDrank <= 0:
                print(
                    "You have",
                    hpPotions,
                    "health potion(s) left. You must drink at least 1 potion.",
                )
                potionsDrank = int(
                    input("Please enter a valid number of health potions to drink: ")
                )

            print()
            # for loop that adds the health to the user and removes the health potions from their inventory
            for _ in range(potionsDrank):
                if playerHp >= maxHp:
                    print(
                        "You are at full health and can't drink",
                        potionsDrank,
                        "health potions",
                    )
                    break
                playerHp += healAmount
                hpPotions -= 1

            # makes sure the user does not have more health than their max health
            if playerHp >= maxHp:
                playerHp = maxHp

            print("Your health is now", playerHp)
            print("You have", hpPotions, "health potion(s) left.\n")
            print("Now you must attack!\n")
            # runs after the user heals
            attackFunc(
                enemy,
                playerHp,
                enemyHp,
                maxHp,
                enemyMaxHp,
                cmd,
                turn,
                playerDmg,
                hpPotions,
                healAmount,
                enemyDmg,
            )
        # forces the user to attack
        else:
            print("You can't heal because you have no potions. Now you must attack!\n")
            attackFunc(
                enemy,
                playerHp,
                enemyHp,
                maxHp,
                enemyMaxHp,
                cmd,
                turn,
                playerDmg,
                hpPotions,
                healAmount,
                enemyDmg,
            )
    # runs if the user chose to attack
    else:
        attackFunc(
            enemy,
            playerHp,
            enemyHp,
            maxHp,
            enemyMaxHp,
            cmd,
            turn,
            playerDmg,
            hpPotions,
            healAmount,
            enemyDmg,
        )


def charStats(pDmg, pHp, maxHp, hpPotions):
    print("-------------------------------------------")
    print("Player damage:", pDmg)
    print("Player health: ({}/{})".format(pHp, maxHp))
    print("Health potions:", hpPotions)
    print("-------------------------------------------")


def enemyStats(enemy, eDmg, eHp):
    print("--------------------")
    print("Enemy:", enemy)
    print("Enemy damage:", eDmg)
    print("Enemy health:", eHp)
    print("--------------------")


# def enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c):
#     e = v[c]
#     enemyHp = e.getEnemyHp()
#     enemyMaxHp = e.getEnemyMaxHp()
#     enemyDmg = e.getEnemyDmg()
#     # Increment the counter
#     c += 1


def enemySetup(v, c):
    e = v[c]
    enemyHp = e.getEnemyHp()
    enemyMaxHp = e.getEnemyMaxHp()
    enemyDmg = e.getEnemyDmg()
    # Increment the counter
    c += 1
    return enemyHp, enemyMaxHp, enemyDmg, c


# displays character info
def charStats(pDmg, pHp, maxHp, hpPotions):
    print("-------------------------------------------")
    print("Player damage:", pDmg)
    print("Player health: ({}/{})".format(pHp, maxHp))
    print("Health potions:", hpPotions)
    print("-------------------------------------------")


# displays enemy info
def enemyStats(enemy, eDmg, eHp):
    print("--------------------")
    print("Enemy:", enemy)
    print("Enemy damage:", eDmg)
    print("Enemy health:", eHp)
    print("--------------------")


v = []
cmd = ""
isValidInput = False

age = charNum = randNum = playerDmg = playerHp = 0
maxHp = enemyHp = enemyMaxHp = enemyDmg = potionsDrank = 0
dmgIncrease, hpIncrease, healAmount = 5, 10, 30
hpPotions = c = turn = 0

name, race, charClass, charWeapon, sex = "", "", "", "", ""
locations = ["Fort Tyforth", "Northhollow", "Trail of Tears", "Dragon's Lair"]
weapons = [
    "Longsword",
    "Magic staff",
    "Oak bow",
    "Platinum longsword",
    "Saphire magic staff",
    "Maple bow",
]
enemyArr = ["goblin", "knight", "spider", "dragon"]
enemy = enemyArr[c]

print("Welcome to Hero of Tyforth!\n")

# character creation
while not isValidInput:
    name = input("Enter the name of your character: ")
    if not name:
        print("You must enter a name!")
    else:
        isValidInput = True

isValidInput = False

while not isValidInput:
    race = input("Enter the race of {}: ".format(name))
    if not race:
        print("You must enter a race!")
    else:
        isValidInput = True

isValidInput = False

while not isValidInput:
    sex = input("Enter the sex of {} (M/F): ".format(name)).upper()
    if len(sex) == 1:
        if sex in ["M", "F"]:
            isValidInput = True
        else:
            print("Error! You can only enter M or F")
    elif not sex:
        print("Error! You must enter either M or F")
    else:
        print("Error! You can't enter more than one character.")

isValidInput = False

print("Please enter a number (18-100): ")
while not isValidInput:
    try:
        age = int(input())
        if age < 18 or age > 100:
            print("Error: age must be in the range (18-100)")
        else:
            isValidInput = True
    except ValueError:
        print("Error: input is not a valid type")

isValidInput = True

print(
    "Enter the number for the class that you want to be: (1 = Warrior, 2 = Mage, 3 = Archer)"
)
while True:
    try:
        charNum = int(input())
        if charNum in [
            Character.WARRIOR.value,
            Character.MAGE.value,
            Character.ARCHER.value,
        ]:
            break
        else:
            print("Invalid class choice. (1 = Warrior, 2 = Mage, 3 = Archer)")
    except ValueError:
        print("Invalid input. Enter a number.")

# Decide the user's stats based on the class they chose
if charNum == Character.WARRIOR.value:
    charClass = "Warrior"
    charWeapon = weapons[0]
    playerDmg = 20
    playerHp = 140
    maxHp = 140
elif charNum == Character.MAGE.value:
    charClass = "Mage"
    charWeapon = weapons[1]
    playerDmg = 30
    playerHp = 120
    maxHp = 120
elif charNum == Character.ARCHER.value:
    charClass = "Archer"
    charWeapon = weapons[2]
    playerDmg = 25
    playerHp = 130
    maxHp = 130

print("\nYou created a character with these attributes:")
print("Name:", name)
print("Race:", race)
print("Sex:", sex)
print("Age:", age)
print("Class:", charClass, "\n")

input("Press Enter to continue...")
print()
print(
    "You live in the Enelidor Kingdom, and live in a town called Fort Tyforth, where you make a living selling weapons."
)
print(
    "You leave your home and head out for the town center to begin setting up your weapons stand."
)
print(
    "You only end up selling three weapons today, and you just barely scrape buy to make ends meet."
)

print(
    "As you're walking back to your home, you overhear someone talking about traveling to Northhollow to become a soldier for king Samuel Woodward."
)
print(
    "Apparently there was a dragon that destroyed a town about 50 miles from Fort Tyforth, and it was rumored to have flown South toward a cliff at the end of the Trail of Tears."
)
print(
    "They mention that there is a massive reward for the soldier who can successfully traverse the Trail of Tears and slay the dragon.\n"
)

print(
    f"({name} talking to themselves): Why don't I travel to Northhollow and prepare to journey through the Trail of Tears?"
)
print(
    "I would rather attempt to traverse the Trail of Tears and slay the dragon, then have to keep making weapons for the rest of my life.\n"
)

print(
    "The next morning you head on your way towards Northhollow in order to enlist on your quest to traverse the Trail of Tears and defeat the dragon."
)
print(
    "After two days of traveling, you reach Northhollow and begin to prepare for your treacherous journey."
)
print("(Game will continue after 40 seconds)\n")

print("You are now ready to embark on your journey...\n")
print("Player class:", charClass)
print("Player weapon:", charWeapon)
print("Player health points:", maxHp)
print("Player damage:", playerDmg, "\n")

# time.sleep(40)

# Creates and initializes objects of class Enemy
goblin = Enemy(10, 50, 50)
v.append(goblin)

knight = Enemy(15, 75, 75)
v.append(knight)

spider = Enemy(20, 90, 90)
v.append(spider)

dragon = Enemy(25, 130, 130)
v.append(dragon)

enemyHp, enemyMaxHp, enemyDmg, c = enemySetup(v, c)

print("You start off on the Trail of Tears and everything seems to be going fine.")
print(f"Suddenly, a {enemy} jumps out in front of and thrusts its sword near you!\n")

# Displays player and enemy stats
enemyStats(enemy, enemyDmg, enemyHp)
charStats(playerDmg, playerHp, maxHp, hpPotions)

cmd = input("What will you do? (a: attack, r: run, h: heal) ")

# Function call
choiceFunc(
    cmd,
    randNum,
    enemy,
    healAmount,
    playerHp,
    hpPotions,
    potionsDrank,
    maxHp,
    enemyHp,
    enemyDmg,
    playerDmg,
    turn,
    enemyMaxHp,
)

# Ends the program if the user died
if playerHp <= 0:
    sys.exit()

print()

cmd = input(
    "You reach a fork in the road and are forced to make a decision, will you go left or right? (l: left, r: right) "
)

# Input validation
while cmd != "l" and cmd != "r":
    print("Please enter a valid command: (l: left, r: right)")
    cmd = input()

# The user can branch off in two directions to determine the rest of the story
if cmd == "l":
    print("You decide to take the path on the left.")
    print(
        "As you journey onward, you come to a mighty looking fortress, with four tall towers at each of its four corners."
    )
    print(
        "You are far enough away that the guards near the entrance of the fort do not see you, so decide that you will... (t: talk to the guards, s: sneak around the fortress)"
    )

    cmd = input()

    while cmd != "t" and cmd != "s":
        print(
            "Please enter a valid command: (t: talk to the guards, s: sneak around the fortress)"
        )
        cmd = input()

    # If the user talks to the guards, they are rewarded with 2 health potions
    if cmd == "t":
        print("\nYou decide that you will talk to the guards.")
        print(
            "As you approach the entrance of the fortress, one guard walks towards you."
        )
        print(
            "You tell the guard that you are on a quest to slay the dragon that has been terrorizing the nearby towns."
        )
        print(
            'The guard responds... "Your quest is honorable, and I hope that you will succeed."'
        )
        print(
            '"I will allow you to pass through. Here\'s two health potions for your journey. Good luck!"'
        )
        hpPotions += 2
        print(
            f"(Two health potions added to inventory. You have {hpPotions} health potions.)"
        )

    else:
        print(
            "\nYou decide that you will attempt to sneak around the fortress, in order to avoid the intimidating guards."
        )
        randNum = random.randint(0, 1)

        if randNum == 0:
            print("You snuck around the fortress successfully!\n")
            c += 2

        else:
            # Sets up enemy variables since the user will now attack the enemy
            enemy = enemyArr[1]
            enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c)

            print(
                "As you sneak around the fortress, you hear footsteps behind you. Suddenly, a guard yells out at you and challenges you to fight him.\n"
            )

            enemyStats(enemy, enemyDmg, enemyHp)
            charStats(playerDmg, playerHp, maxHp, hpPotions)

            cmd = input("What will you do? (a: attack, r: run, h: heal) ")

            choiceFunc(
                cmd,
                randNum,
                enemy,
                healAmount,
                playerHp,
                hpPotions,
                potionsDrank,
                maxHp,
                enemyHp,
                enemyDmg,
                playerDmg,
                turn,
                enemyMaxHp,
            )

            if playerHp <= 0:
                sys.exit()

    print(
        "It is getting dark outside and you need to find somewhere to spend the night. As you continue down the path, you find a small shack and decide to rest for the night.\n"
    )

else:
    c += 1

    print("You decide to take the path on the right.")
    print(
        "It is getting dark outside and you need to find somewhere to spend the night. As you continue down the path, you see a cave entrance with giant stalactites hanging from the ceiling."
    )
    print("You decide that the cave would be the best spot to rest until the dawn.\n")

    print(
        "You enter the cave and notice that there are giant cobwebs about twenty feet in front of you."
    )
    print(
        "You begin to hear faint sounds of something crawling along the rocky floor. The sounds begin to increase in volume and speed."
    )
    print(
        "*Hsssssssss!!!* A giant spider drops down from the ceiling above and confronts you."
    )

    # Sets up enemy variables since the user will now attack the enemy
    enemy = enemyArr[2]
    enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c)

    enemyStats(enemy, enemyDmg, enemyHp)
    charStats(playerDmg, playerHp, maxHp, hpPotions)

    cmd = input("What will you do? (a: attack, r: run, h: heal) ")

    choiceFunc(
        cmd,
        randNum,
        enemy,
        healAmount,
        playerHp,
        hpPotions,
        potionsDrank,
        maxHp,
        enemyHp,
        enemyDmg,
        playerDmg,
        turn,
        enemyMaxHp,
    )

    if playerHp <= 0:
        sys.exit()
    # If the user did not run away from the spider, they get a better weapon
    if cmd != "r":
        if charNum == Character.WARRIOR.value:
            charWeapon = weapons[3]
        elif charNum == Character.MAGE.value:
            charWeapon = weapons[4]
        else:
            charWeapon = weapons[5]

        playerDmg += dmgIncrease

    print()
    print("You find a wooden chest in the cave!")
    print(f"You find a {charWeapon} in the chest! (Your damage is increased by 5)")
    print("Now that the spider is dead, you decide to rest in the cave until morning.")

print(
    "It is morning and you are close to reaching the location where the dragon is thought to reside."
)
print(
    "You got a good night's rest, and are feeling rejuvenated and determined to slay the dragon. (Your max health is increased by 10, and you regain half your health)"
)
maxHp += hpIncrease
playerHp += maxHp // 2

if playerHp > maxHp:
    playerHp = maxHp

print(f"Health is now: ({playerHp}/{maxHp})\n")

print("You keep heading north, anticipating your impending fight with the dragon.")
print(
    "Up ahead, you see a rocky archway lodged between two small hills. It looks as though it's inviting you to enter."
)
print(
    "Your body feels the urge to go there, so you decide that you will see if there is anything through the archway."
)
print(
    "As you arrive at the archway, you realize that this must be the end of the Trail of Tears."
)
print("Through the arch, you see a rocky valley with a cliff at the end.")
print(f"{name} talking to themself:")
print(
    "This matches the location where the dragon is thought to be, but I don't see anything of interest."
)
print(
    "You walk toward the edge of the cliff and hear a faint noise... *wshhh* *wshhhhhhh* *WSHHHHHHHHHHHH!"
)
print(
    "The noise is now very powerful, and you feel a gust of air hit your head from above."
)
print(
    "You look up and see a monstrous looking dragon with bright green scales, and a long neck. The dragon lands behind you."
)
print("The dragon notices you and shoots flames from its mouth towards you!")

# Sets up enemy variables since the user will now attack the final boss
enemy = enemyArr[3]
enemySetup(v, enemyHp, enemyMaxHp, enemyDmg, c)

enemyStats(enemy, enemyDmg, enemyHp)
charStats(playerDmg, playerHp, maxHp, hpPotions)

cmd = input("What will you do? (a: attack, h: heal) ")

bossFunc(
    cmd,
    enemy,
    healAmount,
    playerHp,
    hpPotions,
    potionsDrank,
    maxHp,
    enemyHp,
    enemyDmg,
    playerDmg,
    turn,
    enemyMaxHp,
)
print()

# Ends the program if the user died
if playerHp <= 0:
    sys.exit()
# Runs if the user killed the dragon successfully
else:
    print("Congratulations, you beat the game! :)")
