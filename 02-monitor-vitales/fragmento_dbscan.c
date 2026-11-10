/*
 * Extracto de la implementación de detección de arritmias (DBSCAN multietapa).
 *
 * Original: Task_arritmias.c — código propietario del cliente, no se publica.
 * Aquí solo se incluye la vecindad de las dos etapas, que es donde se ve la
 * diferencia entre la métrica restringida y la euclídea clásica.
 *
 * Los comentarios marcados con [extracto] son añadidos para este repositorio;
 * el resto es código tal como está en el original.
 */

/* [extracto] Métrica de la etapa 2: distancia euclídea pura. */
float euclidean_distance(int point1[2], int point2[2])
{
    return sqrt(pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2));
}

/*
 * [extracto] Etapa 1: vecindad restringida.
 *
 * El punto es {amplitud, tiempo}. Un vecino debe cumplir DOS condiciones:
 *   - delta_abs  <= eps          distancia en amplitud
 *   - delta_abs2 <  width_neigh  ventana temporal
 *
 * La segunda condición es la que adapta DBSCAN a la señal fisiológica: sin
 * ella, dos latidos de morfología idéntica separados minutos se agruparían,
 * y el grupo del paciente dejaría de representar su estado actual.
 */
int get_neighbors(int data[NUM_POINTS][2], int point[2], float eps, int neighbors[NUM_POINTS][2], Bool visited[NUM_POINTS])
{
    int other_point[2] = {0};
    int index = 0;
    int i=0;
    int delta_abs=0;
    int delta_abs2 =0;

    for (i = 0; i < NUM_POINTS; i++)
    {
        other_point[0] = data[i][0];
        other_point[1] = data[i][1];
        delta_abs = abs(point[1]-other_point[1]);
        delta_abs2 = abs(point[0]-other_point[0]);

        if ((!visited[i]) && (delta_abs <= eps)&& ((delta_abs2 < width_neigh)))
        {
            neighbors[index][0] = data[i][0];
            neighbors[index][1] = data[i][1];
            index++;
        }
    }
    return index;
}

/* [extracto] Etapa 2: misma forma, pero con la métrica euclídea y sin ventana. */
int get_neighbors_2(int data[NUM_POINTS_3][2], int point[2], float eps, int neighbors[NUM_POINTS_3][2])
{
    int other_point[2] = {0};
    int index = 0;
    int i=0;
    for (i = 0; i < NUM_POINTS_3; i++)
    {
        other_point[0] = data[i][0];
        other_point[1] = data[i][1];
        if ((euclidean_distance(point, other_point) <= eps))
        {
            neighbors[index][0] = data[i][0];
            neighbors[index][1] = data[i][1];
            index++;
        }
    }
    return index;
}
