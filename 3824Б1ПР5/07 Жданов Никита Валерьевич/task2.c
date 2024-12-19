// Задача 2. Дан непустой массив A, содержащий n натуральных чисел.
// Найти значение минимального из его локальных минимумов.
// Локальный минимум – элемент, который <= левого и правого соседей.
// При отсутствии локальных минимумов вернуть -1.
long long task2(unsigned A[], size_t n)
{
    long long min_local_min = -1; // Изначально -1, если локальных минимумов нет

    // Проверяем элементы массива, начиная со второго и до предпоследнего
    for (size_t i = 1; i < n - 1; i++) {
        // Проверяем, является ли текущий элемент локальным минимумом
        if (A[i] <= A[i - 1] && A[i] <= A[i + 1]) {
            // Если это первый найденный локальный минимум, присваиваем его
            if (min_local_min == -1 || A[i] < min_local_min) {
                min_local_min = A[i];
            }
        }
    }

    // Проверяем крайние элементы, если массив больше 2 элементов
    if (n > 2) {
        if (A[0] <= A[1]) {
            if (min_local_min == -1 || A[0] < min_local_min) {
                min_local_min = A[0];
            }
        }
        if (A[n - 1] <= A[n - 2]) {
            if (min_local_min == -1 || A[n - 1] < min_local_min) {
                min_local_min = A[n - 1];
            }
        }
    }

    return min_local_min; // Возвращаем минимальный локальный минимум или -1
}

