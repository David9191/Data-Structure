#include <stdio.h>

int		inputPlayDay(char **project, int *project_play_day);
void	displayall(char	**project, float *blackhole, int *projects_play_day, int *year, int *month, int *day, float *left_blackhole);
void	calculate(int *year, int *month, int *day);
// 7 7 14 2 21 27 3 27 30 27 5 29 30 35 5 45
int	main(void)
{
	int		year = 2022, month = 5, day = 25;
	float	left_blackhole = 35;
	char	*project[17 /* 과제 개수 */] = {
		"push_swap", "minitalk", "so_long",
		"exam02", "philosophers", "minishell",
		"exam03", "miniRT", "cpp-module",
		"netpractice", "exam04", "inception",
		"webserv", "ft_containers", "exam05",
		"ft_transendence", "exam06"
	};
	float	blackhole[17 /* 과제 개수 */] = {
		29.82, 17.13, 13.53,
		0, 38.9, 27.38, 0,
		47.38, 63.86, 18.22, 0,
		52.07, 92.28, 36.87, 0,
		20.25, 0
	};
	int		projects_play_day[17 /* 과제 개수 */];
	inputPlayDay(project, projects_play_day);
	displayall(project, blackhole, projects_play_day, &year, &month, &day, &left_blackhole);
}

int	inputPlayDay(char **project, int *project_play_day)
{
	for (int i = 0; i < 17 /* 과제 개수 */; i++)
	{
		printf("%s 과제 소요일 : ", project[i]);
		scanf("%d", &project_play_day[i]);
	}
	return (1);
}

void	displayall(char	**project, float *blackhole, int *projects_play_day, int *year, int *month, int *day, float *left_blackhole)
{
	printf("%15s  |  %13s  |  %10s  |  %10s  |  %10s  |  %s  |\n", "과제명", "과제 시작일", "과제 소요일", "블랙홀 플러스", "과제 마침 날짜", "남은 블랙홀");
	for (int i = 0; i < 17 /* 과제 개수 */; i++)
	{
		printf("%13s\t  %d.%d.%d\t   %4d\t\t     %.2f\t    ", project[i], *year, *month, *day, projects_play_day[i], blackhole[i]);
		*day += projects_play_day[i];
		calculate(year, month, day);
		printf("%d.%d.%d\t       ", *year, *month, *day);
		(*day)++; (*left_blackhole)--;
		calculate(year, month, day);
		*left_blackhole = (*left_blackhole - projects_play_day[i]) + blackhole[i];
		printf("%.2f\n", *left_blackhole);
	}
}

void	calculate(int *year, int *month, int *day)
{
	if (((*month == 2 || *month == 4 || *month == 6 || *month == 9 || *month == 11) && *day > 30)
		|| ((*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8
		|| *month == 10 || *month == 12) && *day > 31))
	{
		if (((*month == 2 || *month == 4 || *month == 6 || *month == 9 || *month == 11) && *day > 30))
			*day -= 30;
		else
			*day -= 31;
		(*month)++;
		if (*month > 12)
		{
			*month = 1;
			(*year)++;
		}
	}
}
