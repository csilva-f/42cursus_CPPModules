#include "file.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	file(argv[1]); // abre o ficheiro
		
		if (file.is_open())
		{
			std::stringstream	buffer; // fluxo de memoria para onde o conteudo do ficheiro vai ser lido

			buffer << file.rdbuf(); // extrai o conteudo do ficheiro e insere-o no buffer; obtem um ponteiro para a sequancia associada a stream do ficheiro
			// o operador << e responsavel por esta extracao
			std::string	contents;
			contents = buffer.str();
			file.close();

			std::string		str1 = argv[2];
			std::string		str2 = argv[3];
			std::string		newFileName = argv[1];
			int				index = -1;

			newFileName.append(".replace");
			std::ofstream	newFile;
			newFile.open(newFileName.c_str());
			if (newFile.is_open())
			{
				for (int i = 0; i < (int)contents.size(); i++)
				{
					index = contents.find(str1, i);
					if (index >= 0)
					{
						while (i < index)
							newFile << contents[i++];
						newFile << str2;
						i += str1.size() - 1;
					}
					else
						newFile << contents[i];
				}
				newFile.close();
			}
			else
				std::cout << "Erro na geracao do ficheiro de replace." << std::endl;
		}
		else
			std::cout << "An error occurred while trying to open the file (it does not exist or could not be opened)." << std::endl;
	}
	else
		std::cout << "Wrong number of arguments." << std::endl;
	return 0;
}
