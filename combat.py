print('-------- W O M B A T - C O M B A T --------\n')
print('How many people are playing? (1-4): ', end='')

player=[]
for i in [1]*int(input('')):player.append({})

for i in range(len(player)):player[i]['name']=(input(f'Player {i+1} Name: '))

print('\n\nChoose a class:')
print('1 | Fighter | A basic fighter class, armed with basic weaponry.  Prefers physical force')
print('2 | Archer  | Excells in accuracy and range, preffering to attack from a distance.')
print('3 | Wizard  | A magic class who almost exclusively uses spells for attacks.\n')

for i in range(len(player)):
    player[i]['class']=(input(f"{player[i]['name']}'s Class: ").lower().strip(' '))
    player[i]['class']=((('f')*(player[i]['class'] in ['f','1','fighter']))+(('a')*(player[i]['class'] in ['a','2','archer']))+(('w')*(player[i]['class'] in ['w','3','wizard'])))

