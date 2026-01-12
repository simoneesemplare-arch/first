class effect:
    def __init__(self, nome, duration, healthChangePerTurn, manaChangePerTurn, speedChange, poisonStack):
        self.nome = nome
        self.duration = duration
        self.healthChangePerTurn = healthChangePerTurn
        self.manaChangePerTurn = manaChangePerTurn
        self.speedChange = speedChange
        self.poisonStack = poisonStack
        
class Ability:
    """Represents an ability that can be used in combat.
    
    Attributes:
        nome (str): The name of the ability.
        danno (int): The damage dealt by the ability.
        costo_mana (int): The mana cost required to use the ability.
        mana_heal (int): The amount of mana restored when the ability is used.
        effect_index (int): The index referencing the special effect associated with the ability.
    """
    def __init__(self, nome, danno: int, costo_mana: int, mana_heal: int, effect_index:int):
        self.nome = nome
        self.danno = danno
        self.costo_mana = costo_mana
        self.mana_heal = mana_heal
        self.effect_index = effect_index



class Classe:
    """
    Represents a character class in an RPG game.

    Attributes:
        nome (str): The name of the character class.
        vita (int): The health points of the character.
        mana (int): The mana pool of the character.
        speed (int): The speed stat of the character, affecting turn order and action speed.
        Abilities (list[Ability]): A list of abilities that the character class can use.
    """
    def __init__(self, nome, vita: int, mana: int, speed: int, Abilities: list[Ability]):
        self.nome = nome
        self.vita = vita
        self.mana = mana
        self.speed = speed
        self.Abilities = Abilities