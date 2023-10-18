#include <stdio.h>
#include <dirent.h>
#include <string.h>

DIR* open_db(char* db_name);
void select_db(char* path_local_db);

int main(void) 
{
	int operation = 0;
	char check;
	char path_local_db[255] = "./db";
	DIR *current_dir;
	struct dirent *element;

	while(operation != 2) 
	{
		printf("Select the operation: 1 - Open DB ; 2 - Exit\n");
		scanf("%d%c", &operation, &check);
		if(check != '\n') break;

		switch (operation)
		{
		case 1:
			select_db(path_local_db);
			current_dir = open_db(path_local_db);

			while ((element = readdir(current_dir)) != NULL)
			{
				printf("%s\n", element->d_name);
			}
			
			break;
		
		case 2:
			break;

		default:
			break;
		}
	}
	
	closedir(current_dir);
	return 0;
}

void select_db(char* path_local_db)
{
	path_local_db = strcat(path_local_db, "/db1");
	return;
}

DIR* open_db(char* db_name)
{
	DIR* tmp = opendir(db_name);
	return tmp;
}