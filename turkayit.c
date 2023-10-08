#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int no;
	char geziadi[30];
	char gezitarihi[80];
}gezi;

typedef struct{
	int no;
	char ad[20];
	char soyad[20];
	int telefon;
	char cinsiyet[5];
}yolcu;

void menu(){
	printf("\n\t\t\t\t1.Gezi Ekle\n\t\t\t\t2.Gezi Sil\n\t\t\t\t3.Gezide degisiklik yap\n\t\t\t\t4.Gezileri Listele\n\t\t\t\t5.Yolcu Ekle\n\t\t\t\t6.Yolculari Goruntule\n\t\t\t\t7.Yolcu Sil\n\nSecim yapiniz (cikmak icin 0'a basiniz):\n\n");
}

int main() {
	FILE *ptr;
	int yolcuno,yolcukontrol=0,nokontrol=0,koltukno,yolcusefer,boskontrol=0,secim,i,satirno,numara;
	char oldfilename[30],changetravel[30],yolcusil[30],deletetravel[30],seferadi[30],newfile[20];
	gezi g1 = {0,"",""};
	yolcu y1 = {0,"","",0,""};
					
	ptr = fopen("geziler.bin","wb+");
			for(i=0;i<50;i++)
				fwrite(&g1,sizeof(g1),1,ptr);
	fclose(ptr);
			
		
			
	while(1){
		menu();
		scanf("%d",&secim);
		if(secim==0)
			break;
		switch(secim){
			case 1:
			
			ptr = fopen("geziler.bin","rb+");
			while(1){
			printf("1 ve 50 arasinda bir sefer no giriniz (cikmak icin 0'a basiniz): ");
			scanf("%d",&numara);
			if (numara > 0 && numara <= 50)
				break;
			}
			g1.no = numara;
			while(g1.no != 0){
				
				printf("sefer adini giriniz : ");
				scanf("%s",g1.geziadi);
				printf("gezi tarihi giriniz (gg.aa.yyyy):");
				scanf("%s",g1.gezitarihi);
				
				fseek(ptr,sizeof(g1)*(g1.no-1),SEEK_SET);
				fwrite(&g1,sizeof(g1),1,ptr);
				
				printf("sefer no giriniz (cikmak icin 0'a basiniz): ");
				scanf("%d",&g1.no);
				
			}
			fclose(ptr);
			break;
			
			case 2:
				ptr = fopen("geziler.bin","rb+");
				printf("\t\t\t\t------GUNCEL SEFERLERINIZ--------\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no != 0){
						boskontrol = 1;
						break;
					}
				}
				if (boskontrol != 1){
				
					printf("SEFER KAYDINIZ BULUNMAMAKTADIR!!!! \n\n");
					break;
				}
				fclose(ptr);
				ptr = fopen("geziler.bin","rb+");
				
				//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no!=0)
						printf("\t\t\t\t\t%d %s %s\n",g1.no,g1.geziadi,g1.gezitarihi);
				}
				fclose(ptr);
				
				printf("\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
				printf("silmek istediginiz gezinin nosunu giriniz:");
				scanf("%d",&satirno);
				ptr = fopen("geziler.bin","rb+");
				fseek(ptr,sizeof(g1)*(satirno-1),SEEK_SET);
				fread(&g1,sizeof(g1),1,ptr);
				strcpy(deletetravel,g1.geziadi);
				strcat(deletetravel,g1.gezitarihi);
				strcat(deletetravel,".bin");
				g1.no=0;
				strcpy(g1.geziadi,"");
				strcpy(g1.gezitarihi,"");
				fseek(ptr,sizeof(g1)*(satirno-1),SEEK_SET);
				fwrite(&g1,sizeof(g1),1,ptr);
				remove(deletetravel);
				fclose(ptr);
				break;
			
			case 3:
				ptr = fopen("geziler.bin","rb+");
				printf("\t\t\t\t------GUNCEL SEFERLERINIZ--------\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no != 0){
						boskontrol = 1;
						break;
					}
				}
				if (boskontrol != 1){
				
					printf("SEFER KAYDINIZ BULUNMAMAKTADIR!!!! \n\n");
					break;
				}
				fclose(ptr);
				ptr = fopen("geziler.bin","rb+");
				
				//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no!=0)
						printf("\t\t\t\t\t%d %s %s\n",g1.no,g1.geziadi,g1.gezitarihi);
				}
				fclose(ptr);
				
				printf("\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
				
				ptr = fopen("geziler.bin","rb+");
				
				printf("degistirmek istediginiz gezinin nosunu giriniz:");
				scanf("%d",&satirno);
				fseek(ptr,sizeof(g1)*(satirno-1),SEEK_SET);
				fread(&g1,sizeof(g1),1,ptr);
				strcpy(oldfilename,g1.geziadi);
				strcat(oldfilename,g1.gezitarihi);
				strcat(oldfilename,".bin");		
				printf("yeni sefer adini giriniz: ");
				scanf("%s",g1.geziadi);
				strcpy(changetravel,g1.geziadi);
				strcat(changetravel,g1.gezitarihi);
				strcat(changetravel,".bin");
				printf("yeni gezi tarihi giriniz (gg.aa.yyyy):");
				scanf("%s",g1.gezitarihi);
				g1.no=satirno;
				fseek(ptr,sizeof(g1)*(satirno-1),SEEK_SET);
				fwrite(&g1,sizeof(g1),1,ptr);
				fclose(ptr);
				ptr = fopen(changetravel,"rb+");
					rename(oldfilename,changetravel);
				fclose(ptr);
				break;
			case 4:
				ptr = fopen("geziler.bin","rb+");
				printf("\t\t\t\t------GUNCEL SEFERLERINIZ--------\n");
				//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no!=0)
						printf("\t\t\t\t\t%d %s %s\n",g1.no,g1.geziadi,g1.gezitarihi);
				}
				printf("\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
				fclose(ptr);
				break;
			case 5:
				ptr = fopen("geziler.bin","rb+");
				printf("\t\t\t\t------GUNCEL SEFERLERINIZ--------\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no != 0){
						boskontrol = 1;
						break;
					}
				}
				if (boskontrol != 1){
				
					printf("SEFER KAYDINIZ BULUNMAMAKTADIR!!!! \n\n");
					break;
				}
				fclose(ptr);
				ptr = fopen("geziler.bin","rb+");
				
				
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no != 0){
						boskontrol = 1;
						break;
					}
				}
				if (boskontrol != 1){
				
					printf("SEFER KAYDINIZ BULUNMAMAKTADIR!!!! \n\n");
					break;
				}
				fclose(ptr);
				
				ptr = fopen("geziler.bin","rb+");
				//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no!=0)
						printf("\t\t\t\t\t%d %s %s\n",g1.no,g1.geziadi,g1.gezitarihi);
				}
				printf("\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
				fclose(ptr);
				ptr = fopen("geziler.bin","rb+");
				while(1){			
					printf("yolcu eklemek istediginiz seferin nosunu giriniz:\n ");
					scanf("%d",&yolcusefer);	
					fseek(ptr,sizeof(g1)*(yolcusefer-1),SEEK_SET);
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no==yolcusefer)
						break;
				}
				fseek(ptr,(yolcusefer-1)*sizeof(g1),SEEK_SET);
				fread(&g1,sizeof(g1),1,ptr);
				strcpy(newfile,g1.geziadi);
				strcat(newfile,g1.gezitarihi);
				strcat(newfile,".bin");
				fclose(ptr);
				//dosya oluþturma 
				ptr = fopen(newfile,"rb+");
				if(ptr==NULL){
					ptr=fopen(newfile,"wb+");
					for(i=0;i<50;i++)
						fwrite(&y1,sizeof(y1),1,ptr);
					fclose(ptr);
				}
				ptr = fopen(newfile,"rb+");
				
				/*yeni acýlan dosyaya yolcu eklemesi yapalim*/
				while(1){
				printf("1 ve 50 arasi yolcunun koltuk nosunu giriniz (cikmak icin 0'a basiniz): ");
				scanf("%d",&yolcuno);
				if (yolcuno <=50 && yolcuno>0)
					break;
				}
				y1.no=yolcuno;
				while(y1.no!=0){
					printf("yolcunun adini giriniz: ");
					scanf("%s",y1.ad);
					printf("yolcunun soyadini giriniz: ");
					scanf("%s",y1.soyad);
					printf("yolcunun telefon numarasini giriniz: ");
					scanf("%d",&y1.telefon);
					printf("yolcunun cinsiyetini giriniz: ");
					scanf("%s",y1.cinsiyet);
					fseek(ptr,sizeof(y1)*(y1.no-1),SEEK_SET);
					fwrite(&y1,sizeof(y1),1,ptr);
					printf("1 ve 50 arasi yolcunun koltuk nosunu giriniz (cikmak icin 0'a basiniz): ");
					scanf("%d",&y1.no);
				}
				fclose(ptr);
				break;
			case 6:
				ptr=fopen("geziler.bin","rb+");
				printf("\t\t\t\t------GUNCEL SEFERLERINIZ--------\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no != 0){
						boskontrol = 1;
						break;
					}
				}
				if (boskontrol != 1){
				
					printf("SEFER KAYDINIZ BULUNMAMAKTADIR!!!! \n\n");
					break;
				}
				fclose(ptr);
				
				ptr = fopen("geziler.bin","rb+");
				
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if (g1.no!=0)
						printf("\t\t\t\t\t%d %s %s\n",g1.no,g1.geziadi,g1.gezitarihi);
				}
				printf("\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");	
				while(1){			
					printf("yolcularini goruntulemek istediginiz gezinin nosunu giriniz: ");
					scanf("%d",&yolcusefer);	
					fseek(ptr,sizeof(g1)*(yolcusefer-1),SEEK_SET);
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no==yolcusefer)
						break;
				}
				strcpy(seferadi,g1.geziadi);
				strcat(seferadi,g1.gezitarihi);
				strcat(seferadi,".bin");
				fclose(ptr);
				
				ptr=fopen(seferadi,"rb+");
				
				if(ptr == NULL){
					printf("\nYOLCU KAYDINIZ BULUNAMADI TEKRAR DENEYIN !!!!!!!!!\n");
					break;
				}
				printf("\n\t\t\t\t------GUNCEL YOLCULARINIZ--------\n");
				while(!feof(ptr)){
					fread(&y1,sizeof(y1),1,ptr);
					if(y1.no!=0)
						printf("\t\t\t\t%d %s %s %d %s\n",y1.no,y1.ad,y1.soyad,y1.telefon,y1.cinsiyet);
				}
				fclose(ptr);
				printf("\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
				break;
			case 7:
				ptr = fopen("geziler.bin","rb+");
				printf("\t\t\t\t------GUNCEL SEFERLERINIZ--------\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no != 0){
						boskontrol = 1;
						break;
					}
				}
				if (boskontrol != 1){
				
					printf("SEFER KAYDINIZ BULUNMAMAKTADIR!!!! \n\n");
					break;
				}
				fclose(ptr);
				ptr = fopen("geziler.bin","rb+");
				
				//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no != 0){
						boskontrol = 1;
						break;
					}
				}
				if (boskontrol != 1){
				
					printf("SEFER KAYDINIZ BULUNMAMAKTADIR!!!! \n\n");
					break;
				}
				fclose(ptr);
				
				ptr = fopen("geziler.bin","rb+");
				
				while(!feof(ptr)){
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no!=0)
						printf("\t\t\t\t\t%d %s %s\n",g1.no,g1.geziadi,g1.gezitarihi);
				}
				fclose(ptr);
				
				printf("\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
				ptr= fopen("geziler.bin","rb+");
					while(1){			
					printf("hangi seferden yolcu silmek istiyorsaniz sefer nosunu giriniz:\n ");
					scanf("%d",&yolcusefer);	
					fseek(ptr,sizeof(g1)*(yolcusefer-1),SEEK_SET);
					fread(&g1,sizeof(g1),1,ptr);
					if(g1.no==yolcusefer)
						break;
				}
				strcpy(yolcusil,g1.geziadi);
				
				strcat(yolcusil,g1.gezitarihi);
				strcat(yolcusil,".bin");
				fclose(ptr);
				ptr= fopen(yolcusil,"rb+");
				if(ptr == NULL){
					printf("\nYOLCU KAYDINIZ BULUNAMADI TEKRAR DENEYIN !!!!!!!!!\n");
					break;
				}
				printf("\n\t\t\t\t------GUNCEL YOLCULARINIZ--------\n\n");
				
				//printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
				while(!feof(ptr)){
					fread(&y1,sizeof(y1),1,ptr);
					if(y1.no!=0)
						printf("\t\t\t\t%d %s %s %d %s\n",y1.no,y1.ad,y1.soyad,y1.telefon,y1.cinsiyet);
				}
				fclose(ptr);
				ptr= fopen(yolcusil,"rb+");
				while(1){
				printf("\nsilmek istediginiz yolcunun nosunu giriniz (cikmak icin 0'a basiniz): ");
				scanf("%d",&koltukno);
				fseek(ptr,sizeof(y1)*(koltukno-1),SEEK_SET);
				fread(&y1,sizeof(y1),1,ptr);
				if (y1.no==koltukno)
					break;
				}
				
				strcpy(y1.ad,"");
				strcpy(y1.soyad,"");
				strcpy(y1.cinsiyet,"");
				y1.no=0;
				y1.telefon=0;
				fseek(ptr,sizeof(y1)*(koltukno-1),SEEK_SET);
				fwrite(&y1,sizeof(y1),1,ptr);
				fclose(ptr);
				break;			
		}
	}	
	return 0;
}
