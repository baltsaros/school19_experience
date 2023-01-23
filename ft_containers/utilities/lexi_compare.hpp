/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexi_compare.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:19 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:58:20 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXI_COMPARE_HPP
# define LEXI_COMPARE_HPP

namespace ft {
	template <class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2) {
		for (; (first1 != last1) && (first2 != last2);
				++first1, (void) ++first2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2,
									Compare comp) {
		for (; (first1 != last1) && (first2 != last2);
				++first1, (void) ++first2) {
			if (comp(*first1 < *first2))
				return (true);
			if (comp(*first2 < *first1))
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIt1, class InputIt2>
	bool	equal(InputIt1 first1, InputIt2 last1, InputIt2 first2) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return (false);
			}
		}
		return (true);
	}
}

#endif