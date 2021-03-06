/*
 * TODO
 * Copyright (C) 2019  zerons
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "si_core.h"

SLIST_HEAD(hacking_module_head);

SI_MOD_SUBENV_INIT()
{
	int err;

	INIT_SLIST_HEAD(&hacking_module_head);

	/* load all hacking modules */
	struct slist_head *head;
	head = si_module_get_head(SI_PLUGIN_CATEGORY_HACKING);
	err = si_module_load_all(head);
	if (err) {
		err_dbg(0, "si_module_load_all err");
		goto err1;
	}

	return 0;

err1:
	return -1;
}

SI_MOD_SUBENV_DEINIT()
{
	struct slist_head *head;
	head = si_module_get_head(SI_PLUGIN_CATEGORY_HACKING);
	si_module_unload_all(head);
}

SI_MOD_SUBENV_EARLY_INIT()
{
	return 0;
}

SI_MOD_SUBENV_EARLY_DEINIT()
{
	return;
}

SI_MOD_SUBENV_SETUP(hacking, 1, "analysis");
