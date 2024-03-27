def encontrar_segmento_maximo(n, s, lista):
    suma_actual = 0
    inicio_segmento = 0
    fin_segmento = 0
    mejor_inicio = 0
    mejor_fin = -1

    while fin_segmento < n:
        suma_actual += lista[fin_segmento]

        while suma_actual > s:
            suma_actual -= lista[inicio_segmento]
            inicio_segmento += 1

        if fin_segmento - inicio_segmento > mejor_fin - mejor_inicio:
            mejor_inicio = inicio_segmento
            mejor_fin = fin_segmento

        fin_segmento += 1

    return mejor_fin - mejor_inicio + 1


# Ejemplo de uso
n, s = map(int, input().split())
lista = list(map(int, input().split()))

segmento_maximo = encontrar_segmento_maximo(n, s, lista)
print(segmento_maximo)
