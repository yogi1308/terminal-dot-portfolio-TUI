local loaded_marker = "/tmp/portfolio-nvim-lua-loaded"
local f = assert(io.open(loaded_marker, "w"))
f:write(os.date("%c") .. "\n")
f:close()

local proj = vim.fn.getcwd()
local build_dir = proj .. "/build"

local function notify(msg, level)
	vim.notify(msg, level or vim.log.levels.INFO, { title = "portfolio" })
end

local function do_build(on_success)
	local first = vim.fn.isdirectory(build_dir) == 0
	local cmd = first
		and {
			"bash",
			"-c",
			"cmake -S "
				.. vim.fn.shellescape(proj)
				.. " -B "
				.. vim.fn.shellescape(build_dir)
				.. " && cmake --build "
				.. vim.fn.shellescape(build_dir),
		}
		or { "cmake", "--build", build_dir }

	local orig_win = vim.api.nvim_get_current_win()
	vim.cmd("botright split | resize 10")
	local split_win = vim.api.nvim_get_current_win()
	vim.fn.termopen(cmd, {
		on_exit = function(_, code)
			vim.schedule(function()
				if code == 0 then
					notify("Build OK")
					if on_success and vim.api.nvim_win_is_valid(split_win) then
						vim.api.nvim_win_close(split_win, true)
					end
					if on_success then
						on_success()
					end
				else
					notify("Build failed (see terminal split)", vim.log.levels.ERROR)
				end
			end)
		end,
	})
	vim.api.nvim_set_current_win(orig_win)
end

local function run()
	local exe = build_dir .. "/portfolio"
	if vim.fn.filereadable(exe) == 0 then
		notify("No binary yet; press <leader>cb to build", vim.log.levels.WARN)
		return
	end
	vim.fn.jobstart({ "kitty", "-e", exe }, { detach = true })
end

-- <leader>cb build, <leader>cr run, <leader>cx build + run
vim.keymap.set("n", "<leader>cb", function()
	notify("portfolio: building")
	do_build()
end, { desc = "portfolio: build" })

vim.keymap.set("n", "<leader>cr", function()
	notify("portfolio: running")
	run()
end, { desc = "portfolio: run" })

vim.keymap.set("n", "<leader>cx", function()
	notify("portfolio: building + running")
	do_build(run)
end, { desc = "portfolio: build and run" })

vim.api.nvim_create_autocmd("VimEnter", {
	callback = function()
		notify("portfolio: project keymaps loaded (cb=build, cr=run, cx=build+run)")
	end,
	once = true,
})