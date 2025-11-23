// A megoldásban csak függvényeket kell készíteni, 
// a kód egyéb részeit az ellenőrző kezeli.
// Minden függvény nevét a feladat pontosan definiálja.
// A moodle - n futó kimenetben lesznek extra sorok, "[MEMCHECK]" kezdettel.
// Ezeket az ellenőrző automatikusan teszi oda a memóriakezelés ellenőrzése végett
// (merthogy azt is vizsgálja, és pontlevonás jár a helytelen kezelésért), 
// neked nincs vele dolgod. Az ellenőrző figyel a lefoglalt memóriaterület 
// méretére is! A lebegőpontos számok megjelenítése 2 tizedesjegy 
// pontossággal történjen.
//
// Adott egy ceg struktúra, amely egy cég adatait tárolja.Adattagok:
//
// telephely, változó név : telephely, típus : szöveg(max 30 karakter)
// dolgozók száma, változó név : dolgozok, típus : előjel nélküli egész
// szakmai értékelés, változó név : ertekeles, típus : dupla pontossságú lebegőpontos
// épületek száma, változó név : epuletek, típus : előjel nélküli egész
//
// 1. (10 pont) ALAP RÉSZ(enélkül a többi sem megy) :
//
// Készíts egy kellmemoria függvényt, amely megkap egy egész számot, 
// lefoglal egy dinamikus tömböt ennyi darab cég tárolására, 
// és visszatér a memóriaterület címével.
// Készíts egy torol függvényt, amely megkapja egy dinamikusan lefoglalt cég
// tömb címét, és felszabadítja azt.
// Készíts egy cegEgyetBeker függvényt, amely paraméterben megkap 
// egy darab cég objektumot, mutatóként, és beolvassa az adatait.
// Bekéréskor a változók sorrendje ugyanaz legyen, 
// mint a felső felsorolásnál.
// Készíts egy kiirtomb függvényt, amely paraméterben megkap egy cég tömböt
// a mérettel együtt, és kiírja minden elem adatait.
// Kiíráskor a változók sorrendje ugyanaz legyen, 
// mint a felső felsorolásnál; egy cég adatai egy sorba kerüljenek, 
// szóközzel elválasztva.
//
// 2. (10 pont) Készíts egy feladat2 függvényt, 
// amely megkap egy cég tömböt és annak méretét.
// A függvény térjen vissza a tömb azon elemeinek a számával, 
// amelyeknek a(z) dolgozók száma adattagja kisebb, mint 714.
//
// 3. (10 pont) Készíts egy feladat3 függvényt, 
// amely paraméterben megkap egy fájlnevet.
// A fájl tartalmazza 4 darab cég adatait, ugyanolyan szerkezetben, 
// mint az alapfeladat bemenetén.A függvény olvassa be az értékeket, 
// jelenítse meg mindet ugyanolyan formátumban, 
// ahogy az alapfeladat is kéri, majd jelenítse meg azon elemek darabszámát,
// amelyeknek a(z) dolgozók száma adattagja kisebb, 
// mint 714 (ugyanaz, mint a 2. feladat, csak az új tömbre).
//
// 4. (10 pont) Készíts egy fajlba függvényt, amely megkap egy cég tömböt, 
// annak méretét, valamint egy fájlnevet.
// A függvény írja ki a tömb minden elemének dolgozók száma adatát a fájlba,
// mindet külön sorba.
//
// 5. (10 pont) Hozz létre egy új struktúrát cseretarolo néven, 
// amely kettő ceg típusú mutatót tárol.Legyen egy kigyujtes függvény, 
// amely megkap egy cég tömböt, két egész számot, amik a tömb indexei, 
// valamint egy cseretarolo típusú változót, utóbbit cím szerinti átadással.
// A függvény állítsa be a cseretarolo típusú paramáter által tárolt mutatókat 
// a tömbnek arra a két elemére, amik a paraméterben kapott két indexen találhatóak.
// Legyen egy modosito függvény, amely megkap egy cseretarolo típusú paramétert 
// cím szerinti átadással, és megcseréli a kettő tárolt cég épületek száma adatait.
//
// 6. (10 pont) Készíts egy nagytombcsinalo függvényt, 
// amely négy paramétert kap meg : egy cég tömböt, 
// annak méretét, valamint egy másik cég tömböt, 
// és annak a méretét.A függvény foglaljon egy akkora tömböt, 
// amekkorában a két tömb egymásután éppen elfér.
// Másolja is be a két tömböt az újba, először az elsőt, 
// majd utána a másodikat.A függvény térjen vissza az új tömbbel, 
// de a régi tömböket ne szabadítsa fel.
//
// For example :
//
// Extra adat	Input	Result
// f3.txt tartalma :
// Gyor 711 8.99 1
// Pecs 711 4.77 4
// Nemesvamos 639 8.03 2
// Szombathely 977 5.26 2 12
// Budapest 20 3.00 1
// Pecs 1213 4.42 1
// Nemesvamos 1057 5.47 3
// Szombathely 582 5.42 2
// Gyor 112 8.95 4
// Debrecen 555 6.56 3
// Budapest 790 5.28 3
// Veszprem 459 4.48 4
// Budapest 1010 5.99 4
// Nemesvamos 1481 6.97 5
// Nemesvamos 254 6.84 4
// Pecs 1253 8.41 5
//
// f3.txt
//
// f4.txt
//
// 4 11
//
// 5
// Szombathely 747 4.29 6
// Gyor 1295 4.41 6
// Nemesvamos 1439 3.92 5
// Nemesvamos 448 8.15 4
// Szeged 1444 5.38 2
// A példa kimenet az Előzetes ellenőrzés gombra nyomva elérhető
// (valamit kell írni az 1. feladathoz előtte).
// Answer:(penalty regime : 0 %)

#include <stdio.h>
#include <stdlib.h>

// #define PART2
// #define PART3
// #define PART4
// #define PART5
// #define PART6

struct ceg
{
    char telephely[31];
    unsigned int dolgozok;
    double ertekeles;
    unsigned int epuletek;
};

// Készíts egy kiirtomb függvényt, amely paraméterben megkap egy cég tömböt
// a mérettel együtt, és kiírja minden elem adatait.
// Kiíráskor a változók sorrendje ugyanaz legyen, 
// mint a felső felsorolásnál; egy cég adatai egy sorba kerüljenek, 
// szóközzel elválasztva.
// 1. feladat ->

// Készíts egy kellmemoria függvényt, amely megkap egy egész számot, 
// lefoglal egy dinamikus tömböt ennyi darab cég tárolására, 
// és visszatér a memóriaterület címével.
struct ceg* kellmemoria(int capacity) {
    return (struct ceg*)malloc(sizeof(struct ceg) * capacity);
}

// Készíts egy torol függvényt, amely megkapja egy dinamikusan lefoglalt cég
// tömb címét, és felszabadítja azt.
void torol(struct ceg* arr) {
    free(arr);
    arr = NULL;
}

// Készíts egy cegEgyetBeker függvényt, amely paraméterben megkap 
// egy darab cég objektumot, mutatóként, és beolvassa az adatait.
// Bekéréskor a változók sorrendje ugyanaz legyen, 
// mint a felső felsorolásnál.
void cegEgyetBeker(struct ceg* c) {
    scanf("%s %u %lf %u", c->telephely, &c->dolgozok, &c->ertekeles, &c->epuletek);
}

// Készíts egy kiirtomb függvényt, amely paraméterben megkap egy cég tömböt
// a mérettel együtt, és kiírja minden elem adatait.
// Kiíráskor a változók sorrendje ugyanaz legyen, 
// mint a felső felsorolásnál; egy cég adatai egy sorba kerüljenek, 
// szóközzel elválasztva.
void kiirtomb(struct ceg* c, int len) {
    printf("%s %u %.2lf %u\n", c->telephely, c->dolgozok, c->ertekeles, c->epuletek);
}

// <- 1. feladat 

// 2. (10 pont) Készíts egy feladat2 függvényt, 
// amely megkap egy cég tömböt és annak méretét.
// A függvény térjen vissza a tömb azon elemeinek a számával, 
// amelyeknek a(z) dolgozók száma adattagja kisebb, mint 714.
// 2. feladat ->

int feladat2(struct ceg *c, int len) {
    int count = 0;

    for (int i = 0; i < len; i++)
        if (c[i].dolgozok < 714)
            count++;

    return count;
}

// <- 2. feladat 

// 3. feladat ->

// <- 3. feladat 

// 4. feladat ->

// <- 4. feladat 

// 5. feladat ->

// <- 5. feladat 

// 6. feladat ->

// <- 6. feladat 

int main()
{
    printf("\n--START OF PART1--\n");
    unsigned int meret;
    scanf("%u", &meret);
    struct ceg* tomb;
    tomb = kellmemoria(meret);
    {
        unsigned int i;
        for (i = 0; i < meret; i++)
            cegEgyetBeker(&tomb[i]);
    }
    kiirtomb(tomb, meret);

    printf("\n--END OF PART1--\n");

#ifdef PART2
    printf("\n--START OF PART2--\n");
    unsigned int szamlalas = feladat2(tomb, meret);
    printf("%u\n", szamlalas);
    printf("\n--END OF PART2--\n");
#endif

    char fajlnev3[50];
    scanf("%s", fajlnev3);
#ifdef PART3
    printf("\n--START OF PART3--\n");
    feladat3(fajlnev3);
    printf("\n--END OF PART3--\n");
#endif

    char fajlnev4[50];
    scanf("%s", fajlnev4);
#ifdef PART4
    printf("\n--START OF PART4--\n");
    fajlba(tomb, meret, fajlnev4);
    printf("Fajl tartalma:\n");
    FILE* fp = fopen(fajlnev4, "r");
    char buffer[255];
    if (fp)
    {
        while (fgets(buffer, 255, fp)) {
            printf("%s", buffer);
        }
        fclose(fp);
    }
    printf("\n--END OF PART4--\n");
#endif

    int index1, index2;
    scanf("%d %d", &index1, &index2);
#ifdef PART5
    printf("\n--START OF PART5--\n");
    // Lemásoljuk, hogy ne az eredetit babráljuk
    struct ceg* masolat = kellmemoria(meret);
    unsigned int i;
    for (i = 0; i < meret; i++)
        masolat[i] = tomb[i];
    struct cseretarolo gyujtemeny;
    kigyujtes(masolat, index1, index2, &gyujtemeny);
    modosito(&gyujtemeny);
    printf("Modositas utan:\n");
    kiirtomb(masolat, meret);
    torol(masolat);
    printf("\n--END OF PART5--\n");
#endif

    unsigned int masikmeret;
    scanf("%u", &masikmeret);
#ifdef PART6
    printf("\n--START OF PART6--\n");
    {
        // Lemásoljuk, hogy ne az eredetit babráljuk
        struct ceg* egyiktomb = kellmemoria(meret);
        unsigned int i;
        for (i = 0; i < meret; i++)
            egyiktomb[i] = tomb[i];
        struct ceg* masiktomb = kellmemoria(masikmeret);
        for (i = 0; i < masikmeret; i++)
            cegEgyetBeker(&masiktomb[i]);
        struct ceg* nagytomb = nagytombcsinalo(egyiktomb, meret, masiktomb, masikmeret);
        kiirtomb(nagytomb, meret + masikmeret);
        torol(egyiktomb);
        torol(masiktomb);
        torol(nagytomb);
    }
    printf("\n--END OF PART6--\n");
#endif

    printf("\n--START OF PART1--\n");
    torol(tomb);
    printf("\n--END OF PART1--\n");

    return 0;
}

