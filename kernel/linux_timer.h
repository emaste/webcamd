/*-
 * Copyright (c) 2009 Hans Petter Selasky. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _LINUX_TIMER_H_
#define	_LINUX_TIMER_H_

typedef struct timer_list {
	TAILQ_ENTRY(timer_list) entry;
	void    (*function) (struct timer_list *);
	uint64_t expires;
} timer_list_t;

#define	from_timer(var, cb, field) \
	container_of(cb, typeof(*(var)), field)

#define	timer_setup_on_stack(...) \
	timer_setup(__VA_ARGS__)

#define	destroy_timer_on_stack(...) do { \
} while (0)
	
#define	timer_setup(t,fn,flags) do {	\
	(t)->function = (fn);		\
} while (0)

void	add_timer(struct timer_list *timer);
int	del_timer(struct timer_list *timer);
int	del_timer_sync(struct timer_list *timer);
int	timer_pending(const struct timer_list *timer);
uint64_t get_jiffies_64(void);
void	init_timer(struct timer_list *timer);
void	need_timer(int flag);
int	mod_timer(struct timer_list *timer, unsigned long);

#endif					/* _LINUX_TIMER_H_ */
