-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= "" 
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat
   involves = @pb_enter0:isEnabled()
   name = @le_username0:text()

   if name == "" then return false end

   allowed_usernamechars = {"(", ")", "+", ",", "-", ".", ";", "=", "@", "[", "]", "^", "_", "`", "{", "}", "~", " "}

   for char in string.gmatch(name,".") do
      local found = false;
      if string.match(char,'%l') 
         or string.match(char,'%u') 
         or string.match(char,'%d')then
         found = true
      end
      for k,v in pairs(allowed_usernamechars) do 
         if char == v then found = true end
      end
      if not found then return false end
   end
   return true
end rule


-- password validity
rule validPassword_len
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8 
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content
   involves = @pb_enter0:isEnabled()
   pass = @le_password0:text()

   if string.len(pass) > 14 then return true end

   allowed_passchars = {"!","\"","#","$","%","&","'","*","/",":","<",">","@","\\","|"}
   allowed_profchars = {"(", ")", "+", ",", "-", ".", ";", "=", "@", "[", "]", "^", "_", "`", "{", "}", "~", " "}

   containsDigit = false
   containsSpec = false
   containsUpCase = false
   containsDownCase = false

   for char in string.gmatch(pass, ".") do
      if string.match(char,'%l') then
         containsDownCase = true
      end
      if string.match(char,'%u') then
         containsUpCase = true
      end
      if string.match(char,'%d') then
         containsDigit = true
      end
      for k,v in pairs(allowed_profchars) do 
         containsSpec = true
      end
      for k,v in pairs(allowed_passchars) do 
         containsSpec = true
      end
   end

   if containsDownCase and containsUpCase 
      and containsDigit 
      then return true end
   if (containsDownCase or containsUpCase) 
      and containsDigit and containsSpec
      then return true end
   return false
end rule

