<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateInstalarReglasTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('instalar_reglas', function (Blueprint $table) {
            $table->id();
            $table->string('nombre', 255)->nullable();
            $table->text('regla', 500)->nullable();
            $table->text('detalle', 500)->nullable();
            $table->boolean('estado')->default(false);    
            $table->date('fecha_activada')->nullable();

            $table->timestamps();
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('instalar_reglas');
    }
}
