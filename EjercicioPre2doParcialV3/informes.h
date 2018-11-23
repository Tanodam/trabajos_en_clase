typedef struct
{
    int cantidadUnidadesVendidas;
    int cantidadVentasMayor10000;
    int cantidadVentasMayor20000;
    int cantidadDeTvs;
}Informes;



Informes* informes_new();
void informes_delete();
Informes* informes_newConParametros(int cantidadUnidadesVendidas,int cantidadVentasMayor10000,int cantidadVentasMayor20000,int cantidadDeTvs);

int informes_setCantidadUnidadesVendidas(Informes* this,int cantidadUnidadesVendidas);
int informes_getCantidadUnidadesVendidas(Informes* this,int* cantidadUnidadesVendidas);

int informes_setCantidadVentasMayor10000(Informes* this,int cantidadVentasMayor10000);
int informes_getCantidadVentasMayor10000(Informes* this,int* cantidadVentasMayor10000);

int informes_setCantidadVentasMayor20000(Informes* this,int cantidadVentasMayor20000);
int informes_getCantidadVentasMayor20000(Informes* this,int* cantidadVentasMayor20000);

int informes_setCantidadDeTvs(Informes* this,int cantidadDeTvs);
int informes_getCantidadDeTvs(Informes* this,int* cantidadDeTvs);

#endif // INFORMES_H_INCLUDED
