/*This code is copyright CodeQuests and/or the original submitter. Free to use in original or derivative form for personal or commercial use.Any redistribution in source form must include our URL to this article.*/

#include "stdafx.h"
#include "windows.h"
#include "Rpc.h"
#include <string>

using namespace std;


class Guid
{
public:

   Guid()
   {
      ::memset( &m_guid, 0, sizeof( UUID ) );
   }

   Guid( const UUID& rawGuid ) : m_guid( rawGuid )
   {
   }

   wstring ToString() const
   {
      WCHAR* wzGuid;
      HRESULT hr = StringFromCLSID( m_guid, &wzGuid );
      if( FAILED( hr ) )
      {
         throw hr;
      }

      wstring guid( wzGuid );
      return guid.substr( 1, guid.length() - 2 );
   }

   static bool TryParse( const WCHAR* wzGuid, _Out_ Guid& guid )
   {
      UUID rawGuid;

      wstring parenGuid( L"{" );
      parenGuid += wzGuid;
      parenGuid += L"}" ;

      HRESULT hr = CLSIDFromString( parenGuid.c_str(), &rawGuid );
      if( FAILED( hr ) )
      {
         return false;
      }

      guid = Guid( rawGuid );
      return true;
   }

   // Doesn't create globally unique Guids. Only use on the same machine.
   static Guid NewGuid()
   {
      UUID guid;

      RPC_STATUS status = UuidCreateSequential( &guid );
      if( RPC_S_OK != status )
         throw E_UNEXPECTED;

      return Guid( guid );
   }

private:

   UUID m_guid;
};


int _tmain(int argc, _TCHAR* argv[])
{
   Guid g = Guid::NewGuid();

   wstring gStr = g.ToString();

   wprintf_s( L"%s\n", gStr.c_str() );

   Guid parsed;

   wprintf_s( L"Default value: %s\n", parsed.ToString().c_str() );

   if( Guid::TryParse( gStr.c_str(), parsed ) )
   {
      wprintf_s( L"Parsed correctly\n" );
   }
   else
   {
      wprintf_s( L"Didn't parse\n" );
   }

   const WCHAR* wzBadGuid = L"Hello World";

   if( Guid::TryParse( wzBadGuid, parsed ) )
   {
      wprintf_s( L"Parsed bad guid correctly\n" );
   }
   else
   {
      wprintf_s( L"Failed to parse bad guid\n" );
   }

   return 0;
}
