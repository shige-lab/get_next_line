#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int	main()
{
	int fd = open("test.txt", O_RDONLY );
	char	*result;
	int		i = 1;
	while (1)
	{
		result = get_next_line(fd);
		if (!result)
			break ;
		printf("result%d = %s",i++, result);
		free (result);
	}
	close(fd); 
	printf("\n");
	system ("leaks get_next_line"); 
	return (0);
}

// !マルチファイルディスクリプタ
// int	main()
// {
// 	int fd = open("test.txt", O_RDONLY );
// 	int fd2 = open("test2.txt", O_RDONLY );
// 	char	*result;
// 	char	*result2;
// 	while (1)
// 	{
// 		result = get_next_line(fd);
// 		result2 = get_next_line(fd2);
// 		if (result)
// 			printf("%s", result);
// 		if (result2)
// 			printf("%s", result2);
// 		if (!result && !result2)  
// 			break ;
// 		free (result);
// 		free (result2);
// 	}
// 	close(fd); 
// 	close(fd2); 
// 	printf("\n");
// 	system ("leaks get_next_line"); 
// 	return (0);
// }