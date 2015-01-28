-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty0
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat0
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
rule validPassword_len0
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal0
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content0
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty0
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat0
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len0
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal0
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content0
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty0
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat0
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len0
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal0
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content0
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty0
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat0
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len0
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal0
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content0
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty0
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat0
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len0
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal0
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content0
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty1
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat1
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
rule validPassword_len1
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal1
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content1
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty1
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat1
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len1
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal1
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content1
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty1
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat1
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len1
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal1
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content1
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty1
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat1
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len1
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal1
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content1
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty1
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat1
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len1
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal1
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content1
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty2
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat2
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
rule validPassword_len2
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal2
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content2
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty2
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat2
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len2
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal2
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content2
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty2
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat2
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len2
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal2
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content2
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty2
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat2
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len2
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal2
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content2
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty2
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat2
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len2
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal2
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content2
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty3
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat3
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
rule validPassword_len3
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal3
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content3
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty3
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat3
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len3
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal3
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content3
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty3
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat3
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len3
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal3
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content3
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty3
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat3
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len3
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal3
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content3
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty3
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat3
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len3
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal3
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content3
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty4
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat4
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
rule validPassword_len4
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal4
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content4
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty4
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat4
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len4
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal4
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content4
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty4
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat4
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len4
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal4
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content4
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty4
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat4
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len4
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal4
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content4
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty4
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat4
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len4
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal4
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content4
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty5
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat5
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
rule validPassword_len5
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal5
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content5
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty5
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat5
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len5
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal5
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content5
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty5
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat5
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len5
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal5
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content5
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty5
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat5
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len5
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal5
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content5
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty5
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat5
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len5
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal5
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content5
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty6
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat6
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
rule validPassword_len6
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal6
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content6
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty6
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat6
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len6
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal6
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content6
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty6
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat6
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len6
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal6
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content6
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty6
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat6
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len6
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal6
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content6
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty6
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat6
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len6
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal6
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content6
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty7
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat7
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
rule validPassword_len7
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal7
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content7
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty7
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat7
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len7
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal7
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content7
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty7
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat7
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len7
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal7
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content7
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty7
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat7
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len7
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal7
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content7
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty7
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat7
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len7
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal7
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content7
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty8
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat8
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
rule validPassword_len8
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal8
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content8
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty8
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat8
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len8
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal8
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content8
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty8
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat8
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len8
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal8
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content8
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty8
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat8
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len8
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal8
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content8
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty8
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat8
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len8
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal8
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content8
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty9
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat9
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
rule validPassword_len9
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal9
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content9
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty9
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat9
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len9
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal9
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content9
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty9
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat9
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len9
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal9
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content9
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty9
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat9
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len9
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal9
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content9
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty9
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat9
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len9
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal9
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content9
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty10
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat10
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
rule validPassword_len10
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal10
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content10
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty10
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat10
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len10
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal10
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content10
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty10
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat10
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len10
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal10
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content10
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty10
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat10
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len10
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal10
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content10
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty10
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat10
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len10
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal10
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content10
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty11
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat11
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
rule validPassword_len11
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal11
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content11
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty11
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat11
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len11
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal11
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content11
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty11
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat11
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len11
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal11
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content11
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty11
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat11
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len11
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal11
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content11
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty11
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat11
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len11
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal11
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content11
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty12
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat12
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
rule validPassword_len12
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal12
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content12
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty12
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat12
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len12
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal12
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content12
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty12
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat12
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len12
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal12
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content12
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty12
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat12
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len12
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal12
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content12
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty12
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat12
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len12
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal12
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content12
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty13
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat13
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
rule validPassword_len13
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal13
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content13
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty13
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat13
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len13
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal13
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content13
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty13
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat13
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len13
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal13
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content13
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty13
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat13
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len13
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal13
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content13
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty13
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat13
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len13
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal13
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content13
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty14
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat14
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
rule validPassword_len14
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal14
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content14
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty14
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat14
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len14
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal14
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content14
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty14
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat14
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len14
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal14
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content14
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty14
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat14
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len14
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal14
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content14
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty14
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat14
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len14
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal14
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content14
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty15
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat15
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
rule validPassword_len15
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal15
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content15
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty15
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat15
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len15
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal15
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content15
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty15
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat15
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len15
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal15
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content15
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty15
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat15
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len15
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal15
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content15
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty15
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat15
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len15
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal15
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content15
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty16
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat16
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
rule validPassword_len16
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal16
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content16
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty16
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat16
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len16
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal16
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content16
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty16
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat16
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len16
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal16
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content16
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty16
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat16
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len16
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal16
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content16
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty16
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat16
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len16
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal16
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content16
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty17
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat17
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
rule validPassword_len17
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal17
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content17
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty17
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat17
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len17
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal17
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content17
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty17
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat17
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len17
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal17
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content17
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty17
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat17
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len17
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal17
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content17
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty17
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat17
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len17
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal17
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content17
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty18
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat18
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
rule validPassword_len18
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal18
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content18
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty18
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat18
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len18
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal18
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content18
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty18
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat18
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len18
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal18
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content18
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty18
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat18
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len18
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal18
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content18
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty18
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat18
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len18
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal18
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content18
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty19
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat19
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
rule validPassword_len19
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal19
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content19
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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty19
   involves = @pb_enter1:isEnabled()
   return @le_username1:text() ~= ""
      and @le_password1:text() ~= ""
end rule

-- username format
rule usernameFormat19
   involves = @pb_enter1:isEnabled()
   name = @le_username1:text()

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
rule validPassword_len19
   involves = @pb_enter1:isEnabled()
   if string.len(@le_password1:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal19
   involves = @pb_enter1:isEnabled()
   return @le_password1:text() == @le_confirm1:text()
end rule

-- validPassword_content
rule validPassword_content19
   involves = @pb_enter1:isEnabled()
   pass = @le_password1:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty19
   involves = @pb_enter2:isEnabled()
   return @le_username2:text() ~= ""
      and @le_password2:text() ~= ""
end rule

-- username format
rule usernameFormat19
   involves = @pb_enter2:isEnabled()
   name = @le_username2:text()

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
rule validPassword_len19
   involves = @pb_enter2:isEnabled()
   if string.len(@le_password2:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal19
   involves = @pb_enter2:isEnabled()
   return @le_password2:text() == @le_confirm2:text()
end rule

-- validPassword_content
rule validPassword_content19
   involves = @pb_enter2:isEnabled()
   pass = @le_password2:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty19
   involves = @pb_enter3:isEnabled()
   return @le_username3:text() ~= ""
      and @le_password3:text() ~= ""
end rule

-- username format
rule usernameFormat19
   involves = @pb_enter3:isEnabled()
   name = @le_username3:text()

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
rule validPassword_len19
   involves = @pb_enter3:isEnabled()
   if string.len(@le_password3:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal19
   involves = @pb_enter3:isEnabled()
   return @le_password3:text() == @le_confirm3:text()
end rule

-- validPassword_content
rule validPassword_content19
   involves = @pb_enter3:isEnabled()
   pass = @le_password3:text()

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

-- MainWindow_le_username
-- MainWindow_le_password
-- MainWindow_le_confirm
-- MainWindow_pb_enter


-- values not empty
--
-- pb_enter can not be clicked unless le_username and le_password
-- are not empty
--
rule valuesNotEmpty19
   involves = @pb_enter4:isEnabled()
   return @le_username4:text() ~= ""
      and @le_password4:text() ~= ""
end rule

-- username format
rule usernameFormat19
   involves = @pb_enter4:isEnabled()
   name = @le_username4:text()

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
rule validPassword_len19
   involves = @pb_enter4:isEnabled()
   if string.len(@le_password4:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal19
   involves = @pb_enter4:isEnabled()
   return @le_password4:text() == @le_confirm4:text()
end rule

-- validPassword_content
rule validPassword_content19
   involves = @pb_enter4:isEnabled()
   pass = @le_password4:text()

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

Case)
      and containsDigit and containsSpec
      then return true end
   return false
end rule

