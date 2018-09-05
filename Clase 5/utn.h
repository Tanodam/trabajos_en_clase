int utn_getNumero(      int* pResultado,
                        char mensaje[],
                        char mensajeError[],
                        int minimo,
                        int maximo,
                        int reintentos);
int utn_getCaracter(    char* pResultado,
                        char mensaje[],
                        char mensajeError[],
                        char minimo,
                        char maximo,
                        int reintentos);
float utn_getNumeroFlotante(    float* pResultado,
                                char mensaje[],
                                char mensajeError[],
                                float minimo,
                                float maximo,
                                int reintentos);

int retornarTotal(int miArray[], int cant);
int retornarPromedio(int miArray[], int cant);
int obtenerMayor (int miArray[], int cant);
int obtenerMenor (int miArray[], int cant);
void mostrarListado(int miArray[], int cant);
void mostrarInformacionDelArray(int miArray[], int cant);
void cargarListado(int miArray[], int cant);
int calcularPares (int miArray[], int cant);
int retornarCantidadEntreNotas(int miArray[], int cant, int limiteMaximo, int limiteMinimo);


