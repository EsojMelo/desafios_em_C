import math

''' variáveis '''
i = 1
ant = 0
soma = 0 
pos = 0 
cont = 0
'''processamento'''
while cont < 200: 
    pos = i + ant
    if cont > 200:
        break

    ant = i
    i = pos
    if pos % 2 == 0:
        print(f"{pos}")
        soma = pos + soma
        cont += 1 

'''print da soma dos valores'''
print(f"sum: {soma} ")
print(f"pair count: {cont}")