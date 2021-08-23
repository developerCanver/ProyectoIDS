<?php

namespace App\Http\Controllers;

use App\Models\Btn;
use Illuminate\Http\Request;

class InstalarDaq extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
    }
    
    public function index(Request $request)
    {

        exec('sh bash/installDaq.sh', $daqConfig);


        $guardar = Btn::first();
        $consulta = Btn::first();

        
      if ($daqConfig != "ERROR"){
            $guardar->daq   = 'disabled';
            $guardar->snort   = '';
            $guardar->update();

        }


    return view('instalardaq', [
        'daqConfig'    => $daqConfig,
        'consulta'    => $consulta,
    ]);
    }


}
