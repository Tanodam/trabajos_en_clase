
int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_comparacionPrecioYNombre(Pantalla* pantalla1, Pantalla* pantalla2);
int informar_ordenarPrecioYNombre(Pantalla* array, int limite, int orden);
int informar_valorPantalla(Pantalla* array, int limite);
int informar_promediosValores(Pantalla* array, int limite);
int informar_contratacionesDiasIgualMenorDiez(Pantalla* arrayPan, Contratacion* arrayCon, int limitePan, int limiteCon);

