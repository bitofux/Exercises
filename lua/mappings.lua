---@diagnostic disable: different-requires
require "nvchad.mappings"

-- add yours here

local map = vim.keymap.set

map("n", ";", ":", { desc = "CMD enter command mode" })
map("i", "jk", "<ESC>")
map("n", "`", "<cmd>q!<cr>")
map("n", "t", function()
  local options = vim.bo.ft == "NvimTree" and "nvimtree" or require "configs.menu"
  require("menu").open(options)
end, {})
map("n", "<C-p>", ":tabnext<CR>",{desc = "next tab"})
-- flash
map("n", "m", function()
  require("flash").jump()
end, { desc = "flash jump" })
-- telescope file browser
map("n","<leader>fb",":Telescope file_browser path=%:p:h select_buffer=true<CR>",{desc = "Telescope file_browser"})
-- map({ "n", "i", "v" }, "<C-s>", "<cmd> w <cr>")
