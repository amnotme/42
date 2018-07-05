/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 19:26:03 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/04 23:19:38 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERT_H
# define CONVERT_H
# include <string>
# include <stdexcept>

class Convert {

	public:
		Convert( void );
		Convert( std::string input );
		Convert( Convert const & other );
		~Convert( void );
		Convert & operator=( Convert const & rhs );
	
		class Nan : public std::exception {
			public:
				Nan( std::string input );
				Nan( Nan const & other );
				Nan & operator=( Nan const & rhs );
				virtual ~Nan( void ) throw();
				virtual const char *what() const throw();

				// member functions
				checkInt( Covert &input );
				checkFloat( Convert &input );
				checkDouble( Convert &input );
				checkChar( Convert &input );
		};

		class Impos : public std::exception {
			public:
				Impos( std::string input );
				Impos( Impos const & other );
				Impos & operator=( Impos const & rhs );
				virtual ~Impos( void ) throw();
				virtual const char *what() const throw();

				// member functions
				checkInt( Covert &input );
				checkFloat( Convert &input );
				checkDouble( Convert &input );
				checkChar( Convert &input );
		};

		//getters
		std::string			getInput( void ) const ;
		int					getInt( void ) const ;
		float				getFloat( void ) const ;
		double				getDouble( void ) const ;
		char				getChar( void ) const ;

		//setters			
		void				setInput( std::string  input ) ;
		void				setInt( int intVal ) ;
		void 				setFloat( float floatVal ) ;
		void 				setDouble( double doubleVal ) ;
		void				setChar( char charVal ) ;
		void				parseInput( char *argument ); 
	
	
	
	private:

		std::string			_input;
		int					_convertInt;
		float				_convertFloat;
		double				_convertDouble;
		char				_convertChar;	
};

#endif
