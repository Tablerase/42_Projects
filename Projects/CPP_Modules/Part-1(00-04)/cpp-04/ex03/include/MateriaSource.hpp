/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcutte <rcutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:27:16 by rcutte            #+#    #+#             */
/*   Updated: 2024/04/22 16:32:54 by rcutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H_
#define MATERIASOURCE_H_

#include "../include/AMateria.hpp"
#include "../include/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
    std::string source_name_;
    int         source_slots_;
    AMateria    **source_;
  public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(const MateriaSource &obj);
    MateriaSource &operator=(const MateriaSource &other);
    virtual void learnMateria(AMateria*);
    virtual AMateria *createMateria(std::string const &type);
};

#endif