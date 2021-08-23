<?php

namespace App\Http\Controllers;

use App\Models\Btn;
use Illuminate\Http\Request;

class InstalarSnort extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
    }
    

    public function index(Request $request)
    {

        exec('sh bash/installSnortConfig.sh', $snortConfig);
  

        $guardar = Btn::first();
        $consulta = Btn::first();

        
      if ($snortConfig != "ERROR"){
            $guardar->snort   = 'disabled';
            $guardar->red   = '';
            $guardar->update();

        }


    return view('instalarsnort', [
        'snortConfig'    => $snortConfig,
        'consulta'    => $consulta,
    ]);
    }

}
