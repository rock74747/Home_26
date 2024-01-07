#include <iostream>
#include <string>



struct Movie {
	std::string title = "noname";
	int year;
	std::string genre = "noname";
	unsigned int duration = 0;
	unsigned int price = 0;
}; 

void print_movie(const Movie& film) {
	std::cout << "Название фильма:" << film.title << std::endl;
	std::cout << "Год выхода фильма:" << film.year << std::endl;
	std::cout << "Жанр фильма:" << film.genre << std::endl;
	std::cout << "Продолжительность фильма: " << film.duration << " min" << std::endl; 
	std::cout << "Цена за диск фильма: " << film.price << " рублей" << std::endl;
}

Movie expensiv (Movie* films, int number_film) {
	unsigned int max =0;
	for (int i = 0; i < number_film; i++) {
		if (films[i].price > max)
			max = films[i].price;
	}
		for (int i = 0; i < number_film; i++) {
			if (films[i].price == max)
			return films[i];
		}
		
}

void update_info(Movie* film) {

	std::cout << "Выберите, какую информацию о фильме необходимо обновить : \n";
	std::cout << "1. Название \n";
	std::cout << "2. Год выхода \n";
	std::cout << "3. Жанр \n";
	std::cout << "4. Продолжительность \n";
	std::cout << "5. Цена за диск \n";

	std::cout << "Ввод->";
	short information;
	std:: cin >> information;
	std::string str;
	switch (information) {
	case 1:
		std:: cout << "Введите новое название фильма: \n";
		std:: cin >> str;
		film->title = { str };
		std::cout << "Новое название фильма: " << film->title << "\n";
		break;

	case 2:
		int n;
		std::cout << "Введите год выхода фильма: \n";
		std::cin >> n;
		film->year = n;
		std::cout << "Новый год выхода фильма: " << film->year << "\n";
		break;
	case 3:
		std::cout << "Введите жанр фильма: \n";
		std::cin >> str;
		film->genre = { str };
		std::cout << "Новый жанр фильма: " << film->genre << "\n";
		break;
	case 4:
		std::cout << "Введите новую продолжительность фильма: \n";
		std::cin >> n;
		film->duration = n;
		std::cout << "Новая продолжительность фильма: " << film->duration << " мин.\n";
		break;
	case 5:
		std::cout << "Введите цену за диск фильма: \n";
		std::cin >> n;
		film->price = n;
		std::cout << "Новая цена за диск фильма: " << film->price << " руб.\n";
		break;
	}

}
	
		

int main()
{
	setlocale(LC_ALL, "Russian");

	Movie film1{"Терминатор", 2004, "Фантастика", 125, 425 };
	Movie film2{ "Бриллиантовая рука", 1974, "Комедия", 103, 850 };
	Movie film3{ "Маска", 2002, "Комедия", 112, 630 };
	Movie film4{ "Чужой", 1998, "Фантастика", 118, 750 };
	Movie film5{ "Санктум", 2010, "Приключения", 119, 520 }; 
	
	print_movie(film1); 
	std::cout << "----------" << std::endl;
	print_movie(film2);
	std::cout << "----------" << std::endl;
	print_movie(film3);
	std::cout << std::endl;
	
	const int number_film = 5;
	Movie films[] = {film1, film2, film3,film4,film5 };
	std::cout << "Фильм с самой высокой ценой за диск: \n";
	print_movie(expensiv(films, number_film)); 
	std::cout << std::endl;
	update_info(&film1);
	print_movie(film1);
return 0;
}

