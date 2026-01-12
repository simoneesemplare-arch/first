import Pg
import random
def player_turn(player, enemy):
    turn=True
    print(f"\nÈ il turno di {player['nome']}!")
    print("Scegli un'abilità da usare:")
    while turn:
        for i, ability in enumerate(player['class'].Abilities):
            print(f"{i}. {ability.nome} (Danno: {ability.danno}, Costo Mana: {ability.costo_mana}, Mana Heal: {ability.mana_heal})")
        choice = int(input("Inserisci il numero dell'abilità: "))
        ability = player['class'].Abilities[choice]
        if player['mana'] < ability.costo_mana:
            print("Mana insufficiente! scegli un altra abilità.")
            turn= True
        else:
            player['mana'] -= ability.costo_mana
            enemy['vita'] -= ability.danno
            player['mana'] += ability.mana_heal
            print(f"{player['nome']} usa {ability.nome}!")
            turn = False

effects=[
    Pg.effect("null", duration=0, healthChangePerTurn=0, manaChangePerTurn=0, speedChange=0, poisonStack=0),
    Pg.effect("Veleno", duration=3, healthChangePerTurn=-5, manaChangePerTurn=0, speedChange=0, poisonStack=1),
    Pg.effect("Rigenerazione", duration=5, healthChangePerTurn=10, manaChangePerTurn=0, speedChange=0, poisonStack=0),
    Pg.effect("Elettricità", duration=2, healthChangePerTurn=-10, manaChangePerTurn=0, speedChange=-2, poisonStack=0),
    Pg.effect("Velocità", duration=4, healthChangePerTurn=0, manaChangePerTurn=0, speedChange=5, poisonStack=0),
    Pg.effect("Bruciatura", duration=3, healthChangePerTurn=-8, manaChangePerTurn=0, speedChange=0, poisonStack=0)
]
abilities=[
    Pg.Ability("Colpo Fisico", danno=15, costo_mana=0, mana_heal=0, effect_index=0),
    Pg.Ability("Dardo di Fuoco", danno=25, costo_mana=10, mana_heal=0, effect_index=5),
    Pg.Ability("Veleno Tossico", danno=10, costo_mana=8, mana_heal=0, effect_index=1),
    Pg.Ability("Lampo Elettrico", danno=20, costo_mana=12, mana_heal=0, effect_index=3),
    Pg.Ability("Incantesimo di Rigenerazione", danno=0, costo_mana=15, mana_heal=0, effect_index=2),
    Pg.Ability("Benedizione della Velocità", danno=0, costo_mana=10, mana_heal=0, effect_index=4),
    Pg.Ability("Pozione di Mana", danno=0, costo_mana=0, mana_heal=20, effect_index=0)
]
classi=[
    Pg.Classe("Guerriero", vita=100, mana=30, speed=10, Abilities=[abilities[0], abilities[1], abilities[6]]),
    Pg.Classe("Mago", vita=70, mana=100, speed=12, Abilities=[abilities[1], abilities[3], abilities[4], abilities[6]]),
    Pg.Classe("Ladro", vita=80, mana=50, speed=15, Abilities=[abilities[0], abilities[2], abilities[5], abilities[6]])
]
scelta = int(input(f"Scegli la tua classe (inserisci un numero tra 0-{len(classi)}): "))
player_class = classi[scelta]
npc_class = random.choice(classi)
print(f"Hai scelto la classe: {player_class.nome}")
print("Le tue abilità sono:")
for ability in player_class.Abilities:
    print(f"- {ability.nome}: Danno: {ability.danno}, Costo Mana: {ability.costo_mana}, Mana Heal: {ability.mana_heal}")
