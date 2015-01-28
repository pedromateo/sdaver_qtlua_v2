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
rule valuesNotEmpty20
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat20
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
rule validPassword_len20
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal20
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content20
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
rule valuesNotEmpty21
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat21
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
rule validPassword_len21
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal21
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content21
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
rule valuesNotEmpty22
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat22
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
rule validPassword_len22
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal22
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content22
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
rule valuesNotEmpty23
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat23
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
rule validPassword_len23
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal23
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content23
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
rule valuesNotEmpty24
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat24
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
rule validPassword_len24
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal24
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content24
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
rule valuesNotEmpty25
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat25
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
rule validPassword_len25
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal25
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content25
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
rule valuesNotEmpty26
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat26
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
rule validPassword_len26
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal26
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content26
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
rule valuesNotEmpty27
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat27
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
rule validPassword_len27
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal27
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content27
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
rule valuesNotEmpty28
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat28
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
rule validPassword_len28
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal28
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content28
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
rule valuesNotEmpty29
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat29
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
rule validPassword_len29
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal29
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content29
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
rule valuesNotEmpty30
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat30
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
rule validPassword_len30
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal30
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content30
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
rule valuesNotEmpty31
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat31
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
rule validPassword_len31
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal31
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content31
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
rule valuesNotEmpty32
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat32
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
rule validPassword_len32
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal32
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content32
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
rule valuesNotEmpty33
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat33
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
rule validPassword_len33
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal33
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content33
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
rule valuesNotEmpty34
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat34
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
rule validPassword_len34
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal34
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content34
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
rule valuesNotEmpty35
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat35
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
rule validPassword_len35
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal35
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content35
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
rule valuesNotEmpty36
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat36
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
rule validPassword_len36
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal36
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content36
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
rule valuesNotEmpty37
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat37
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
rule validPassword_len37
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal37
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content37
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
rule valuesNotEmpty38
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat38
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
rule validPassword_len38
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal38
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content38
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
rule valuesNotEmpty39
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat39
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
rule validPassword_len39
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal39
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content39
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
rule valuesNotEmpty40
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat40
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
rule validPassword_len40
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal40
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content40
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
rule valuesNotEmpty41
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat41
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
rule validPassword_len41
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal41
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content41
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
rule valuesNotEmpty42
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat42
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
rule validPassword_len42
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal42
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content42
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
rule valuesNotEmpty43
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat43
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
rule validPassword_len43
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal43
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content43
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
rule valuesNotEmpty44
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat44
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
rule validPassword_len44
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal44
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content44
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
rule valuesNotEmpty45
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat45
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
rule validPassword_len45
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal45
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content45
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
rule valuesNotEmpty46
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat46
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
rule validPassword_len46
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal46
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content46
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
rule valuesNotEmpty47
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat47
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
rule validPassword_len47
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal47
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content47
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
rule valuesNotEmpty48
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat48
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
rule validPassword_len48
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal48
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content48
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
rule valuesNotEmpty49
   involves = @pb_enter0:isEnabled()
   return @le_username0:text() ~= ""
      and @le_password0:text() ~= ""
end rule

-- username format
rule usernameFormat49
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
rule validPassword_len49
   involves = @pb_enter0:isEnabled()
   if string.len(@le_password0:text()) < 8
      then return false end
   return true
end rule

-- validPassword_equal
rule validPassword_equal49
   involves = @pb_enter0:isEnabled()
   return @le_password0:text() == @le_confirm0:text()
end rule

-- validPassword_content
rule validPassword_content49
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

