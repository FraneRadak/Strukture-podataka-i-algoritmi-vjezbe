typedef struct {
	float x;
	float y;
	float z;
}VRH;

typedef struct {
	VRH* vrh;
	float normala[3];
	unsigned short boja;
}TROKUT;

typedef struct {
	TROKUT* trokut;
	unsigned int broj_trokuta;
}OBJEKT;

OBJEKT* citaj_STL(){
	OBJEKT* tijelo = (OBJEKT*)malloc(sizeof(OBJEKT));
	int k = 0;
	FILE * fp = fopen("primjerbin.stl","rb");
	if (!fp) {
		printf("Error oppening file\n");
		return 0;
	}
	else
	{
		printf("File succesfully opened\n");
		printf("**************************\n");
	}
	fseek(fp, sizeof(char)*80, SEEK_SET);
	fread(&(tijelo->broj_trokuta), sizeof(unsigned int), 1, fp);
	int broj_trokuta = tijelo->broj_trokuta;
	tijelo->trokut = (TROKUT*)malloc(sizeof(TROKUT) * broj_trokuta);

	for ( k = 0;k <broj_trokuta ;k++) {
		tijelo->trokut[k].vrh = (VRH*)malloc(sizeof(VRH) * 3);

		for (int i = 0;i < 3;i++) {
			fread(&(tijelo->trokut[k].normala[i]), sizeof(float), 1, fp);
		}


		for (int i = 0;i < 3;i++) {
			fread(&(tijelo->trokut[k].vrh[i].x), sizeof(float), 1, fp);
			fread(&(tijelo->trokut[k].vrh[i].y), sizeof(float), 1, fp);
			fread(&(tijelo->trokut[k].vrh[i].z), sizeof(float), 1, fp);
		}
	
		fread(&(tijelo->trokut[k].boja), sizeof(unsigned short), 1, fp);
	}
	/* ispis
	for (k = 0;k < broj_trokuta;k++) {

		for (int i = 0;i < 3;i++) {
			printf("%f ", tijelo->trokut[k].normala[i]);
		}
		printf("\n");
		for (int i = 0;i < 3;i++) {
			printf("%f ", tijelo->trokut[k].vrh[i].x);
			printf("%f ", tijelo->trokut[k].vrh[i].y);
			printf("%f ", tijelo->trokut[k].vrh[i].z);
			printf("\n");
		}
		printf("\n");
		printf("%d ", tijelo->trokut[k].boja);
		printf("\n");
		printf("*************************\n");
	}
	*/
	fclose(fp);
	return tijelo;
}

void PISI_bin(OBJEKT*tijelo){
	int i,k;
	FILE* fp = fopen("zadatak.stl", "wb");
	if (!fp)
		printf("ERROR CREATING FILE");
	else
		printf("FILE SUCESSFULLY CREATED\n");
	printf("***********************");
	char x = 0;
	for (int i=0;i<80;i++)
		fwrite(&x, 1, 1, fp);
	fwrite(&(tijelo->broj_trokuta), sizeof(unsigned int), 1, fp);
	for (k = 0;k < tijelo->broj_trokuta;k++) {

		for (int i = 0;i < 3;i++) {
			fwrite(&(tijelo->trokut[k].normala[i]), sizeof(float), 1, fp);
		}


		for (int i = 0;i < 3;i++) {
			fwrite(&(tijelo->trokut[k].vrh[i].x), sizeof(float), 1, fp);
			fwrite(&(tijelo->trokut[k].vrh[i].y), sizeof(float), 1, fp);
			fwrite(&(tijelo->trokut[k].vrh[i].z), sizeof(float), 1, fp);
		}

		fwrite(&(tijelo->trokut[k].boja), sizeof(unsigned short), 1, fp);
	}
	

}


void fun(OBJEKT* p) {
	int i, j, k;
	FILE* fp = fopen("zadataktext.stl", "w");
	if (!fp)
		printf("ERROR OPENNING FILE\n");
	else
		printf("FILE SUCCESFULLY OPENED\n");
	printf("*******************************");
	fprintf(fp, "solid CAD\n");
	for (int i = 0;i < p->broj_trokuta;i++)
	{
		fprintf(fp, "  facet normal %f %f %f\n", p->trokut[0].normala[0], p->trokut[0].normala[1], p->trokut[0].normala[2]);
		fprintf(fp, "    outer loop\n");
		for (int j = 0;j < 3;j++)
			fprintf(fp,"      vertex %f %f %f\n", p->trokut[0].vrh[j].x, p->trokut[0].vrh[j].x, p->trokut[0].vrh[j].x);
		fprintf(fp,"    endloop\n");
		fprintf(fp,"  end facet\n");
	}
}
void OSLOBODI(OBJEKT* pointer) {
	for (int i = 0;i < pointer->broj_trokuta;i++)
	{
		free(pointer->trokut[i].vrh);
	}
	free(pointer->trokut);
	free(pointer);
}
void LIBRARY(OBJEKT*tijelo) {
	FILE* fp1 = fopen("zadataktext.stl", "r");
	if (fp1 == NULL )
		printf("Cannot open file\n");
	for (int i = 0;i < tijelo->broj_trokuta;i++)
	{
		fscanf(fp1,"facet normal %f %f %f\n", &tijelo->trokut[i].normala[0], &tijelo->trokut[i].normala[1], &tijelo->trokut[i].normala[2]);
		fscanf(fp1,"outer loop\n");
		for (int j = 0;j < 3;j++) 
			fscanf(fp1,"vertex %f %f %f", &tijelo->trokut[i].vrh[j].x, &tijelo->trokut[i].vrh[j].y, &tijelo->trokut[i].vrh[j].z);
		fscanf(fp1,"endloop\n");
		fscanf(fp1,"end facet");
	}
}






