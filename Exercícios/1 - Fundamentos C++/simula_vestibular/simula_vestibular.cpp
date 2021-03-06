#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>


using namespace std;

int numero_aleatorio(int max, int min)
{
    uniform_int_distribution<int> randomDist(min, max);
    random_device rd;
    mt19937 randomNumbers(rd());
    return randomDist(randomNumbers);
}

void criaLista()
{
    ofstream arquivo;
    arquivo.open("vestibular.txt");

    arquivo << "Inscrição|\tIdade|\tCurso|\tPontuação";

    for (int i = 1; i <= 826; i++)
    {
        int registro = 1000 + i;
        int idade = numero_aleatorio(30, 17);
        int pontuacao = numero_aleatorio(5000, 0);
        int curso = numero_aleatorio(16, 11);

        arquivo << "\n";
        arquivo << "\t";
        arquivo << registro;
        arquivo << "\t";
        arquivo << idade;
        arquivo << "\t\t";
        arquivo << curso;
        arquivo << "\t\t";
        arquivo << pontuacao;
    }

    arquivo << "\n";
    arquivo << "-1";

    arquivo.close();

    //cout << "lista criada\n";
}

/*caminha na linha até a posição do curso*/
int busca_curso(char *vetor_de_busca, int pos_contra_barra)
{

    int dezena = 0;
    int unidade = 0;

    dezena = vetor_de_busca[pos_contra_barra + 11];
    unidade = vetor_de_busca[pos_contra_barra + 12];

    return (dezena - 48) * 10 + (unidade - 48);
}



int main()
{
    /*para verificar se temos pelo menos 3 candidatos por vaga em cada curso*/
    int contador_curso_11 = 0;
    int contador_curso_12 = 0;
    int contador_curso_13 = 0;
    int contador_curso_14 = 0;
    int contador_curso_15 = 0;
    int contador_curso_16 = 0;

    char vetor_de_busca[20000] = {}; //recebe todos os caracteres do arquivo
    int posicao = 0;                 //incrementa a cado novo caractere lido do arquivo

    int vetor_pos_contra_barra[827] = {}; //guarda a posição do todos os \n
    int cont = 0;                         //incrementa cada vez que um \n é lido do arquivo

    

    do
    {
        /*
        caso não seja gerado 3 candidatos por vaga, é necessário resetar as variáveis
        para fazer uma nova verificação.
        */

        contador_curso_11 = 0;
        contador_curso_12 = 0;
        contador_curso_13 = 0;
        contador_curso_14 = 0;
        contador_curso_15 = 0;
        contador_curso_16 = 0;

        cont = 0;
        posicao = 0; //contador pro vetor_de_busca

        criaLista();

        ifstream arquivoEntrada; //objeto de leitura
        
        arquivoEntrada.open("vestibular.txt"); //abre o arquivo

        if (arquivoEntrada.is_open())
        {

            while (!arquivoEntrada.eof())
            {
                //vetor_de_busca recebe todos os caracteres do arquivo

                arquivoEntrada.get(vetor_de_busca[posicao]);

                if (vetor_de_busca[posicao] == '\n')
                {
                    vetor_pos_contra_barra[cont] = posicao;
                    cont += 1;
                }

                posicao += 1;
            }
            arquivoEntrada.close();
        }
        else
        {
            cout << "Não foi possível abrir o arquivo" << endl;
        }

        for (int i = 0; i < 826; i++)
        {
            //a função busca_curso está retornando o valor correspondente do curso

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 11)
            {
                contador_curso_11++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 12)
            {
                contador_curso_12++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 13)
            {
                contador_curso_13++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 14)
            {
                contador_curso_14++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 15)
            {
                contador_curso_15++;
            }

            if (busca_curso(vetor_de_busca, vetor_pos_contra_barra[i]) == 16)
            {
                contador_curso_16++;
            }
        }

    } while (contador_curso_11 < 120 || contador_curso_12 < 120 || contador_curso_13 < 120 || contador_curso_14 < 120 || contador_curso_15 < 120 || contador_curso_16 < 120);

    cout << "Curso 11 numero de candidatos: " << contador_curso_11 << endl;
    cout << "Curso 12 numero de candidatos: " << contador_curso_12 << endl;
    cout << "Curso 13 numero de candidatos: " << contador_curso_13 << endl;
    cout << "Curso 14 numero de candidatos: " << contador_curso_14 << endl;
    cout << "Curso 15 numero de candidatos: " << contador_curso_15 << endl;
    cout << "Curso 16 numero de candidatos: " << contador_curso_16 << endl;


    return 0;

}