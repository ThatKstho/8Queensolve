/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <agoumihunter@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:22:04 by magoumi           #+#    #+#             */
/*   Updated: 2018/10/29 08:43:11 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *str, const char *to_find, int n)
{
	int a;
	int b;
	int l;

	a = 0;
	if (to_find[a] == '\0')
		return ((char*)str);
	while (str[a] != '\0' && n--)
	{
		b = 0;
		l = n;
		if (str[a] == to_find[b])
		{
			while (to_find[b] != '\0' && to_find[b] == str[a + b] && l-- + 1)
				b++;
			if (to_find[b] == '\0')
				return ((char*)&str[a]);
		}
		a++;
	}
	return (0);
}
